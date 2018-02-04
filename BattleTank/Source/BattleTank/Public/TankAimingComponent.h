// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "UObject/UObjectGlobals.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	void AimAt(FVector HitLocation, float LaunchSpeed);

	UTankAimingComponent();

	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

private:
	UStaticMeshComponent* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
	
};
