// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Camera/PlayerCameraManager.h"
#include "RealTankPlayerController.generated.h"

UCLASS()
class BATTLETANK_API ARealTankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	ATank * GetControlledTank() const;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.3333;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 100000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

};
