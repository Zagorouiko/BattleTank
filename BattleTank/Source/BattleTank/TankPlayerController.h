// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "Engine/World.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()


public:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

private:
	
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D Screenlocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector& LookDirection, FVector& OutHitLocation) const;

	void AimTowardsCrosshair();

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = .5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = .33333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.f;
};
