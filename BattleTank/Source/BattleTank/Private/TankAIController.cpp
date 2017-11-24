// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "BattleTank.h"
#include "TankAimingComponent.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	Super::Tick(DeltaTime);
	if (!ensure(PlayerTank && ControlledTank)) { return; }
	
		//Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);

		//Aim towards the player
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		if (AimingComponent->GetFiringState() == EFiringState::Locked)
		{
			AimingComponent->Fire();
		}
}

