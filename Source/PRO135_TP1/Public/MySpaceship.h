#pragma once

#include "MyBall.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MySpaceship.generated.h"

UCLASS()
class PRO135_TP1_API AMySpaceship : public APawn
{
	GENERATED_BODY()

public:
	AMySpaceship();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	TSubclassOf<class AMyBall> BallClass;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float TurnSpeed = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rotation")
	float RollMax = 40.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rotation")
	float YawMax = 20.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rotation")
	float RotateSpeed = 2.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Shot")
	int MagazineSize = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Shot")
	float ReloadTime = 200.f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Shot")
	int BallsLeft;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Shot")
	float ReloadTimeLeft;
	
private:
	void Steering(float Value);

	void Shot();
	void SpawnBall();

	void Reload();
};
