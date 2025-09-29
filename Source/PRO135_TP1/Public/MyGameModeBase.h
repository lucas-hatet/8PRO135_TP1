#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "MyGameModeBase.generated.h"

UCLASS()
class PRO135_TP1_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	TSubclassOf<class AMyAsteroid> AsteroidClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnRange = 10000.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnFreq = .1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float YMovements = .1f;

	UFUNCTION()
	void SpawnAsteroid();

private:
	FTimerHandle SpawnTimerHandle;
};