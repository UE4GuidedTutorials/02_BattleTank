// Fill out your copyright notice in the Description page of Project Settings.

#include "RealTankPlayerController.h"

void ARealTankPlayerController::BeginPlay()
{
	Super::BeginPlay();//makes sure that override is working correctly
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)//checks to see if tank not controlled and protects pointer
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));//reports controlled tank
	}

}

void ARealTankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ARealTankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}

void ARealTankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ARealTankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);//intializes VSX and VSY to any viewport size
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);//calculates position of crosshair in pixels
	
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}

	return true;
}

bool ARealTankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)//hits anything that is visible
		)
		{
		HitLocation = HitResult.Location;
		return true;
		}
	HitLocation = FVector(0);
	return false;
}

bool ARealTankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; //cannot define type of CWL inside DeprojectSPTW

	return DeprojectScreenPositionToWorld
	(
		ScreenLocation.X,//.X accesses the X parameter of ScreenLocation
		ScreenLocation.Y,//same as above
		CameraWorldLocation,
		LookDirection
	);
} 

