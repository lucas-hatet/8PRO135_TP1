#include "MyAsteroid.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"

AMyAsteroid::AMyAsteroid()
{
	PrimaryActorTick.bCanEverTick = true;

	AsteroidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AsteroidMesh"));
	RootComponent = AsteroidMesh;
	
	Radius = FMath::RandRange(50.0f, MaxRandomRadius);
	float Scale = Radius / 100.0f;
	AsteroidMesh->SetWorldScale3D(FVector(Scale));
    
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->InitialSpeed = 1000.0f;
	ProjectileMovement->MaxSpeed = 1000.0f;
	ProjectileMovement->ProjectileGravityScale = 0.0f;
	ProjectileMovement->bInitialVelocityInLocalSpace = false;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->bIsHomingProjectile = false;
	ProjectileMovement->Velocity = FVector(100.0f, 0.0f, 0.0f);

}

void AMyAsteroid::BeginPlay()
{
	Super::BeginPlay();
}