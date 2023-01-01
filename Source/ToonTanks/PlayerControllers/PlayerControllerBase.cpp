// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"

void APlayerControllerBase::SetPlayerEnabledState(bool SetPlayerEnabled)
{
    if (SetPlayerEnabled)
    {
        if (GetPawn())
            GetPawn()->EnableInput(this);
    }
    else
    {
        if (GetPawn())
            GetPawn()->DisableInput(this);
    }

    bShowMouseCursor = SetPlayerEnabled;
}