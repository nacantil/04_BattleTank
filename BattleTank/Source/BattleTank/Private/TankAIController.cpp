// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay() 
{
    Super::BeginPlay();
    auto PlayerTank = GetPlayerTank();
    if (!PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController not posessing a tank"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(PlayerTank->GetName()));
    }
}

ATank* ATankAIController::GetPlayerTank() const
{
    return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}