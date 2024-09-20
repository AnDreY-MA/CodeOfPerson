// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/CodeOfPersonGameModeBase.h"

#include "GameState/CodeOfPersonGameState.h"

ACodeOfPersonGameModeBase::ACodeOfPersonGameModeBase(const FObjectInitializer& InInitializer) :
	Super(InInitializer)
{
	GameStateClass = ACodeOfPersonGameState::StaticClass();

}