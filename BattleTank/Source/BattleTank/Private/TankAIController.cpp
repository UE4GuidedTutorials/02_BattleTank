// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"




void ATankAIController::BeginPlay()
{
	Super::BeginPlay();//makes sure that override is working correctly
	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)//checks to see if tank not controlled and protects pointer
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));//reports controlled tank
	}

}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr;}
	return Cast<ATank>(PlayerPawn);
}

