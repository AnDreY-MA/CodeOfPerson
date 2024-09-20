// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ModularsActors/ModularGameMode.h"
#include "CodeOfPersonGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CODEOFPERSON_API ACodeOfPersonGameModeBase : public AModularGameMode
{
	GENERATED_BODY()

public:
	explicit ACodeOfPersonGameModeBase(const FObjectInitializer& InInitializer = FObjectInitializer::Get());
	
};