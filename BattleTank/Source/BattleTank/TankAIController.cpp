// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
//#include "Tank.h"


void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	

	if(ensure(PlayerTank)) {

		//This passes information to the the tank movement components "RequestDirectMove()" overrided function. Super abstract
		MoveToActor(PlayerTank, AcceptanceRadius);

		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire();
	}	
}

