// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API APawnTower : public APawnBase
{
	GENERATED_BODY()

private:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
    float FireRate = 2.0f;

    FTimerHandle FireRateTimerHandle;

    void CheckFireCondition();

public:

    virtual void Tick(float DeltaTime) override;

protected:

    virtual void BeginPlay() override;
};
