// Fill out your copyright notice in the Description page of Project Settings.

#include "PawnTurret.h"
#include "PawnTank.h"
#include "Kismet/GameplayStatics.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
    Super::BeginPlay();

    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}
// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APawnTurret::CheckFireCondition()
{
    // If player == null || isDead then bail
    if (!PlayerPawn)
    {
        return;
    }
    // If player IS in range then fire
    if(DistanceToPlayer() <= FireRange)
    {
        UE_LOG(LogTemp, Warning, TEXT("Fire condition checked"));
    }
}

float APawnTurret::DistanceToPlayer()
{
    if (!PlayerPawn)
    {
        return 0;
    }

    return FVector::Dist(PlayerPawn->GetActorLocation(), this->GetActorLocation());
}
