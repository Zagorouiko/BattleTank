// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "TankAimingComponent.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	//log here
	UE_LOG(LogTemp, Warning, TEXT("BEGINPLAY TankController"));
	if (!ensure(AimingComponent)) {	return;	}
	FoundAimingComponent(AimingComponent);
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair() {

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

	if (!ensure(AimingComponent)) { return; }
	FVector OutHitLocation; //out parameter

	if (GetSightRayHitLocation(OutHitLocation)) {
		//Passes out parameter of hit location into the tank.cpp "aim at" function
		AimingComponent->AimAt(OutHitLocation);
	}
}

//out parameter is sent in here then returns changed. Get world location of line trace through cross hair, true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const {

	//Find the cross-hair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D((ViewportSizeX*CrossHairXLocation), (ViewportSizeY*CrossHairYLocation));

	FHitResult HitResult;
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		//Line trace along that Look direction and see what we hit (up to a max range)
		GetLookVectorHitLocation(LookDirection, OutHitLocation);	
	}

	

	return true;
}

//Deproject screen position of the cross hair to a world direction
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection ) const {

	FVector CameraWorldPosition; //To be discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldPosition, LookDirection);

}

bool ATankPlayerController::GetLookVectorHitLocation(FVector& LookDirection, FVector& OutHitLocation) const {

	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility)) {
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0);
	return false;
}



