// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
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

private:
	ATank* GetControlledTank() const;

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	void AimTowardsCrosshair();

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = .5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = .33333;

};
