// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/Actors/InteractableActor.h"

AInteractableActor::AInteractableActor(const FObjectInitializer& InInitializer) :
	Super(InInitializer)
{
	PrimaryActorTick.bCanEverTick = false;

}