// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/Components/InteractionComponent.h"

UInteractionComponent::UInteractionComponent(const FObjectInitializer& InInitializer) :
	Super(InInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UInteractionComponent::Grab(AGrabableActor* InGrabActor)
{
	GrabableActor = InGrabActor;
}

