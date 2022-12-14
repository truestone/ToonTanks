// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBaase.h"

// Sets default values
APawnBaase::APawnBaase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APawnBaase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawnBaase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawnBaase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

