// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
		AMovingPlatform();

protected:
		virtual void Tick(float DeltaSeconds) override;
		virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float MovementSpeed = 5.f;
	
	UPROPERTY(EditAnywhere, Meta=(MakeEditWidget = true))
	FVector TargetLocation;

	FVector CurrentLocation;

	
};
