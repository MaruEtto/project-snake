// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"
#include "SnakeActorBase.h"

// Sets default values
AFood::AFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFood::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFood::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead)
	{
		auto Snake = Cast<ASnakeActorBase>(Interactor);
		if (IsValid(Snake))
		{
			Snake->AddLastSnakeElement();
			FRotator myRot(0, 0, 0);

			int RandomX = FMath::RandRange(-450, 450);
			int RandomY = FMath::RandRange(-450, 450);
			FVector myLoc(RandomX, RandomY, -20);

			GetWorld()->SpawnActor<AFood>(this->GetClass(), myLoc, myRot);

			Destroy();
		}
	}

}

