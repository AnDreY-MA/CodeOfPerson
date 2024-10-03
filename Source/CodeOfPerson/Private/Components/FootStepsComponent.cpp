// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/FootStepsComponent.h"

UFootStepsComponent::UFootStepsComponent(const FObjectInitializer& InInitializer) :
	Super(InInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;

}