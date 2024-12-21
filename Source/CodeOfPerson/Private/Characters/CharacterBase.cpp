// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CharacterBase.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterBase)

ACharacterBase::ACharacterBase(const FObjectInitializer& InInitializer) :
	Super(InInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

