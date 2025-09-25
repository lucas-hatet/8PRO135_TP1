#include "MyXp.h"
#include "Kismet/GameplayStatics.h"
#include "MySpaceship.h"



AMySpaceship* TargetSpaceship = nullptr;



AMyXp::AMyXp()
{
	PrimaryActorTick.bCanEverTick = true;
}



void AMyXp::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMySpaceship::StaticClass(), FoundActors);

	if (FoundActors.Num() > 0)
	{
		TargetSpaceship = Cast<AMySpaceship>(FoundActors[0]);
	}
}



void AMyXp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector MoveDirection = FVector::ZeroVector;

	if (TargetSpaceship)
	{
		FVector ToShip = TargetSpaceship->GetActorLocation() - GetActorLocation();
		ToShip.Normalize();
		MoveDirection += ToShip;
	}

	TArray<AActor*> AllXp;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMyXp::StaticClass(), AllXp);

	for (AActor* Actor : AllXp)
	{
		if (Actor == this) continue;

		FVector ToOther = GetActorLocation() - Actor->GetActorLocation();
		float Distance = ToOther.Size();

		float MinDistance = 100.f;
		if (Distance < MinDistance && Distance > KINDA_SMALL_NUMBER)
		{
			ToOther.Normalize();
			float Strength = (MinDistance - Distance) / MinDistance;
			MoveDirection += ToOther * Strength * 2.0f;
		}
	}

	if (!MoveDirection.IsNearlyZero())
	{
		MoveDirection.Normalize();
		SetActorLocation(GetActorLocation() + MoveDirection * Speed * DeltaTime);
	}
}