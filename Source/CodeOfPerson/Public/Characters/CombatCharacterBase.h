// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "Interfaces/CombatComponentInterface.h"
#include "AbilitySystemInterface.h"
#include "CombatCharacterBase.generated.h"

class UCombatSystemComponent;

UCLASS(Abstract)
class CODEOFPERSON_API ACombatCharacterBase : public ACharacterBase, public ICombatComponentInterface, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	explicit ACombatCharacterBase(const FObjectInitializer& InInitializer = FObjectInitializer::Get());

	// ICombatComponentInterface Implementation
	UCombatSystemComponent* GetCombatSystemComponent_Implementation() const;
	// End ICombatComponentInterface

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCombatSystemComponent> CombatSystemComponent;
};
