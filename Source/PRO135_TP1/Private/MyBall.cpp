#include "MyBall.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h" 

AMyBall::AMyBall()
{
	PrimaryActorTick.bCanEverTick = true;

	ProjectileComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileComp->InitialSpeed = 2000.f;
	ProjectileComp->MaxSpeed = 2000.f;
	ProjectileComp->bRotationFollowsVelocity = true;
}

void AMyBall::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

