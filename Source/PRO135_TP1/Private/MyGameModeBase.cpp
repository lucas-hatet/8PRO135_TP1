#include "MyGameModeBase.h"
#include "MyAsteroid.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Math/UnrealMathUtility.h"

void AMyGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &AMyGameModeBase::SpawnAsteroid, SpawnFreq, true);
}

void AMyGameModeBase::SpawnAsteroid()
{
    if (!AsteroidClass) return;

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (!PlayerPawn) return;

    float PlayerY = PlayerPawn->GetActorLocation().Y;
    FVector SpawnLocation(4000.f, FMath::RandRange(PlayerY - SpawnRange, PlayerY + SpawnRange), 0.f);
    FRotator SpawnRotation = FRotator::ZeroRotator;

    FActorSpawnParameters SpawnParams;
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

    AMyAsteroid* NewAsteroid = GetWorld()->SpawnActor<AMyAsteroid>(AsteroidClass, SpawnLocation, SpawnRotation, SpawnParams);

    if (NewAsteroid)
    {
        if (NewAsteroid->ProjectileMovement)
        {
            FVector VelocityVector(
                0.0f,
                FMath::RandRange(-YMovements, YMovements),
                0.0f
            );
            NewAsteroid->ProjectileMovement->Velocity = VelocityVector;
        }
    }
}