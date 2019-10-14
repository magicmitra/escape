// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "Gameframework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	
	// Top down way to get the pawn.
	// Rememvber: ActorThatOpens returns a pointer to an AActor.
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor()
{
	// find actor
	AActor* Owner = GetOwner();

	// create rotator
	FRotator NewRotation = FRotator(0.0f, -60.0f, 0.0f);

	// set the door roatation
	Owner->SetActorRotation(NewRotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the trigger volume on every frame
	// If the ActorThatOpens is in the volume, then open the door
	if (PressurePlate && PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
	}
}

