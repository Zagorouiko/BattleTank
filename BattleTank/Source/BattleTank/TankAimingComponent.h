// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Forward declaration, allows you to reference UtankBarrel type in the header.
//This essentially lets you define more than one class in the header file
//Remember, most of the time headers should only be included in the cpp unless inheriting from a class

UENUM()
enum class EFiringStatus : uint8 {
	Reloading,
	Aiming,
	Locked
};

class UTankBarrel;
class UTankTurret;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BluePrintCallable, Category = Setup)
	void Initialize(UTankBarrel* Barrel, UTankTurret* Turret);
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation, float LaunchSpeed);

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void SetTurretReference(UTankTurret* TurretToSet);

	void MoveBarrelTowards(FVector AimDirection);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringStatus = EFiringStatus::Aiming;

private:
	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;

};
