// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {
	
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw) {
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw) {
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

//Receives information from the tankAI controller "MoveToActor()" function
void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) {
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();  
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto DotProductThrow =  FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(DotProductThrow);
	//UE_LOG(LogTemp, Warning, TEXT("%s Vectoring to %s"), *TankName, *MoveVelocity.ToString());
}
