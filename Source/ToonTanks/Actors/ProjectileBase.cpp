// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileBase.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AProjectileBase::AProjectileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
    RootComponent = ProjectileMesh;

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
    ProjectileMovement->InitialSpeed = MovementSpeed;
    ProjectileMovement->MaxSpeed = MovementSpeed;

    ParticleTrail = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle Trail"));
    ParticleTrail->SetupAttachment(RootComponent);

    InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();

    ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectileBase::OnHit);
    UGameplayStatics::PlaySoundAtLocation(this, LaunchSound, GetActorLocation());
}

void AProjectileBase::OnHit(UPrimitiveComponent* HitComponent,
    AActor* OtherActor, UPrimitiveComponent* OtherComp,
    FVector NormalImpulse, const FHitResult& Hit)
{
    AActor* MyOwner = GetOwner();

    if (!MyOwner)
    {
        return;
    }

    if (OtherActor && OtherActor != this && OtherActor != MyOwner)
    {
        UGameplayStatics::ApplyDamage(OtherActor, Damage,
            MyOwner->GetInstigatorController(), this, DamageType);
        UGameplayStatics::SpawnEmitterAtLocation(this,
            HitParticle, GetActorLocation());
        UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());
        UGameplayStatics::PlayWorldCameraShake(this,
            HitShake, GetActorLocation(), 0, 10000);
    }

    Destroy();
}
