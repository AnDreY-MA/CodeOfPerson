// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ModularsActors/ModularCharacter.h"
#include "CharacterBase.generated.h"

UCLASS(Abstract)
class CODEOFPERSON_API ACharacterBase : public AModularCharacter
{
	GENERATED_BODY()

public:
	explicit ACharacterBase(const FObjectInitializer& InInitializer);

protected:	
	virtual void BeginPlay() override;

};