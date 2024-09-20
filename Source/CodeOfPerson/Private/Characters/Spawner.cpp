// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Spawner.h"


ASpawner::ASpawner(const FObjectInitializer& InInitializer) :
	Super(InInitializer), bSpawnBegin(false), Count(0)
{
	PrimaryActorTick.bCanEverTick = true;
	
}


void ASpawner::Spawn_Implementation()
{
}