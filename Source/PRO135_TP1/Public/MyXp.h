// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyXp.generated.h"

UCLASS()
class PRO135_TP1_API AMyXp : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyXp();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movements")
	float Speed = 1000.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
