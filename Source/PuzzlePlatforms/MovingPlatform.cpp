// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() ever frame. 
	PrimaryActorTick.bCanEverTick = true;
	// Set static mesh to moveable
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	// tells Server to communicate with Clients
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}

void AMovingPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Movement is calculated on server, sets client location
	if (HasAuthority()) {
		CurrentLocation = GetActorLocation();
		FVector GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
		//CurrentLocation.X -= MovementSpeed * DeltaSeconds;
		FVector Direction = (GlobalTargetLocation - CurrentLocation).GetSafeNormal();
		SetActorLocation(CurrentLocation + Direction * MovementSpeed * DeltaSeconds);
	}
}