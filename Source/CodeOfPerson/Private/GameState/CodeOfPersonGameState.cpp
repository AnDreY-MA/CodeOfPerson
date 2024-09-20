// Fill out your copyright notice in the Description page of Project Settings.


#include "GameState/CodeOfPersonGameState.h"

#include "Components/CombatManagerComponent.h"


ACodeOfPersonGameState::ACodeOfPersonGameState(const FObjectInitializer& InInitializer) :
	Super(InInitializer)
{
	CombatManagerComponent = CreateDefaultSubobject<UCombatManagerComponent>("Combat Manager");
	
}

UCombatManagerComponent* ACodeOfPersonGameState::GetCombatManagerComponent_Implementation() const
{
	return CombatManagerComponent.Get();
	
}