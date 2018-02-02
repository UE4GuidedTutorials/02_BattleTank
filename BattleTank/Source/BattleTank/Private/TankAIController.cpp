// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();//makes sure that override is working correctly
	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));

	auto AITank = AIControlledTank();
	if (!AITank)//checks to see if tank not controlled and protects pointer
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(AITank->GetName()));//reports controlled tank
	}

}

ATank* ATankAIController::AIControlledTank() const
{
	return Cast<ATank>(GetPawn());//not sure what this does

}

