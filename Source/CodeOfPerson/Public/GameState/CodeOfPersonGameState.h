// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CombatManagerInterface.h"
#include "ModularsActors/ModularGameState.h"
#include "CodeOfPersonGameState.generated.h"


class UCombatManagerComponent;

UCLASS(Blueprintable)
class CODEOFPERSON_API ACodeOfPersonGameState : public AModularGameState, public ICombatManagerInterface
{
	GENERATED_BODY()

public:
	explicit ACodeOfPersonGameState(const FObjectInitializer& InInitializer = FObjectInitializer::Get());

	/// ICombatManagerInterface Implementation
	virtual UCombatManagerComponent* GetCombatManagerComponent_Implementation() const override;

private:
	UPROPERTY(EditDefaultsOnly, Category="Combat|Enemy")
	TObjectPtr<UCombatManagerComponent> CombatManagerComponent;
	
};