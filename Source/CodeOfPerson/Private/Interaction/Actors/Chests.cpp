// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/Actors/Chests.h"

AChests::AChests(const FObjectInitializer& InObjectInitializer) :
	Super(InObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;

}

void AChests::Open_Implementation()
{
}
