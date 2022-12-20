// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTower.h"

void APawnTower::CheckFireCondition()
{
    UE_LOG(LogTemp, Warning, TEXT("Fire Condition Checked"));
}

void APawnTower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APawnTower::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTower::CheckFireCondition, FireRate, true);
}







