// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "BattleTank.h"
#include "Tank.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	Super::Tick(DeltaTime);
	if (PlayerTank) 
	{
		//Move towards player

		//Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire();
	}
}

