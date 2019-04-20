// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile_.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	auto TankName = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("DONKEY: C++ Construct, %s"), *TankName);
}

void ATank::BeginPlay() {
	Super::BeginPlay(); //ALWAYS NEEDED FOR BP "BEGIN PLAY" TO RUN
	//UE_LOG(LogTemp, Warning, TEXT("DONKEY: Tank.cpp Being Play"));
}

void ATank::AimAt(FVector HitLocation) {
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire() {

	if (!ensure(Barrel)) { return; }
	bool isReloaded = ((FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds);

	if (isReloaded) { 	

		auto Projectile = GetWorld()->SpawnActor<AProjectile_>( //This spawn returns a type "projectile"
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")), 
			Barrel->GetSocketRotation(FName("Projectile")));

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}



