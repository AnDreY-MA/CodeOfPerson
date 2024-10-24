// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/PersonFootComponent.h"


UPersonFootComponent::UPersonFootComponent(const FObjectInitializer& InInitializer) :
	Super(InInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UPersonFootComponent::BeginPlay()
{
	Super::BeginPlay();

}