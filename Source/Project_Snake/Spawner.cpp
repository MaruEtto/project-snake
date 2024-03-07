// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"
#include "Food.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnFood();
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawner::SpawnFood()
{
	if (SpawnActorArray.Num())
	{
		int32 RandomBonusIndex = FMath::RandRange(0, SpawnActorArray.Num() - 1);
		auto ClassForSpawn = SpawnActorArray[RandomBonusIndex];

		int RandomX = FMath::RandRange(-500, 500);
		int RandomY = FMath::RandRange(-500, 500);
		auto SpawnLocation = FVector(RandomX, RandomY, 65);

		auto CurrentBonusActor = GetWorld()->SpawnActor<AActor>(ClassForSpawn, FTransform(SpawnLocation));

		auto CurrentBonus = Cast<AFood>(CurrentBonusActor);

		if (CurrentBonus)
		{
			CurrentBonus->SetLifeSpan(15.f);
			CurrentBonus->BonusActivated.AddDynamic(this, &ASpawner::SpawnFood);
		}
	}
}

