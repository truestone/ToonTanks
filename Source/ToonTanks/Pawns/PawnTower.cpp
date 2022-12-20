// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTower.h"
#include "PawnTank.h"
#include "Kismet/GameplayStatics.h"

void APawnTower::CheckFireCondition()
{
    if (!PlayerPawn)
    {
        return;
    }

    if (ReturnDistanceToPlayer() <= FireRange)
    {
        // Fire
        UE_LOG(LogTemp, Warning, TEXT("Fire Condition Success"));
    }
}

float APawnTower::ReturnDistanceToPlayer()
{
    if (!PlayerPawn)
    {
        return 0.0f;
    }

    return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}

void APawnTower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APawnTower::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, 
        &APawnTower::CheckFireCondition, FireRate, true);

    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}







