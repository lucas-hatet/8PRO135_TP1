#include "MySpaceship.h"
#include "Components/InputComponent.h"



AMySpaceship::AMySpaceship()
{
	PrimaryActorTick.bCanEverTick = true;
}



void AMySpaceship::BeginPlay()
{
	Super::BeginPlay();
	BallsLeft = MagazineSize;
	ReloadTimeLeft = ReloadTime;
}



void AMySpaceship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float CurrentRoll = GetActorRotation().Roll;
	AddActorWorldOffset(FVector(0, CurrentRoll * TurnSpeed, 0));
	
	if (BallsLeft <= 0) {
		if (ReloadTimeLeft <= 0)
		{
			BallsLeft = MagazineSize;
			ReloadTimeLeft = ReloadTime;
		}
		else
		{
			ReloadTimeLeft--;
		}
	}
}



void AMySpaceship::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Steering", this, &AMySpaceship::Steering);
	
	PlayerInputComponent->BindAction("Shot", IE_Pressed, this, &AMySpaceship::Shot);
	
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &AMySpaceship::Reload);
}



void AMySpaceship::Steering(float Value)
{
	FRotator CurrentRotation = GetActorRotation();
	float TargetRoll, TargetYaw;
	
	if (FMath::Abs(Value) > KINDA_SMALL_NUMBER)
	{
		TargetRoll = Value * RollMax;
		TargetYaw = Value * YawMax;
	}
	
	float NewRoll = FMath::FInterpTo(CurrentRotation.Roll, TargetRoll, GetWorld()->GetDeltaSeconds(), RotateSpeed);
	float NewYaw = FMath::FInterpTo(CurrentRotation.Yaw, TargetYaw, GetWorld()->GetDeltaSeconds(), RotateSpeed);
	
	FRotator NewRotation(CurrentRotation.Pitch, NewYaw, NewRoll);
	SetActorRotation(NewRotation);
}



void AMySpaceship::Shot()
{
	if (BallsLeft <= 0)	return;
	else
	{
		BallsLeft -= 1;
		SpawnBall();
	}
}

void AMySpaceship::SpawnBall()
{
	if (BallClass == nullptr) return;

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = GetInstigator();

	FVector ShipLocation = GetActorLocation();

	FVector ForwardVector = GetActorForwardVector();
	FVector SpawnLocation = ShipLocation + ForwardVector * 200.f;

	GetWorld()->SpawnActor<AMyBall>(BallClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);
}

void AMySpaceship::Reload() { BallsLeft = 0; }