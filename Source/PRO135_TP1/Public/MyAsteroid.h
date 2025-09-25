#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyAsteroid.generated.h"

class UStaticMeshComponent;
class UProjectileMovementComponent;

UCLASS()
class PRO135_TP1_API AMyAsteroid : public AActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Collision")
	float MaxRandomRadius = 150.0f;

public:
	AMyAsteroid();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* AsteroidMesh;

	UPROPERTY(EditAnywhere, Category="Movement")
	FVector Velocity;

	UPROPERTY(EditAnywhere, Category="Collision")
	float Radius;
};
