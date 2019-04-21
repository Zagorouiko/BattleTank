// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class AProjectile_;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties


protected:
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile_> ProjectileBlueprint;

private:

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000.0; //1000 m/s

	ATank();

	UTankBarrel* Barrel = nullptr;

	UPROPERTY(EditDefaultsOnly)
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;

};
