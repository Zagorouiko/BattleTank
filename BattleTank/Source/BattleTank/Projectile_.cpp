// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile_.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectile_::AProjectile_()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Particle Component"));

	ProjectileMovementComponent->bAutoActivate = false;

}

// Called when the game starts or when spawned
void AProjectile_::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile_::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile_::LaunchProjectile(float speed) {
	ProjectileMovementComponent->SetVelocityInLocalSpace(FVector::ForwardVector * speed);
	ProjectileMovementComponent->Activate();
}

