// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() ever frame. 
	PrimaryActorTick.bCanEverTick = true;
	// Set static mesh to moveable
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	CurrentLocation = GetActorLocation();
	//UE_LOG(LogTemp, Warning, TEXT("GetActorLocation = %s", *CurrentLocation.ToString()));
	CurrentLocation.X -= MovementSpeed * DeltaSeconds;
	//UE_LOG(LogTemp, Warning, TEXT("CurrentLocation = %s", *CurrentLocation.ToString()));
	SetActorLocation(CurrentLocation);
}