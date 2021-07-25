// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank/BattleTank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() 
{
    Super::BeginPlay();
    auto ControlledTank = GetControlledTank();
    if (!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController not posessing a tank"));
    }
    else 
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
    }
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    AimTowardsCrosshair();
    //UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() const
{
    if (!GetControlledTank()) 
    {
        return;
    }
    FVector HitLocation; // Out paramater
    if (GetSightRayHitLocation(HitLocation))
    {
        UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());

    }
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
    HitLocation = FVector(1.0);
    return true;
}