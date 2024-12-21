// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CombatCharacterBase.h"
#include "Components/CombatSystemComponent.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CombatCharacterBase)

ACombatCharacterBase::ACombatCharacterBase(const FObjectInitializer& InInitializer) :
	Super(InInitializer)
{
	CombatSystemComponent = CreateDefaultSubobject<UCombatSystemComponent>("CombatSystemComponentA");
}

UCombatSystemComponent* ACombatCharacterBase::GetCombatSystemComponent_Implementation() const
{
	return CombatSystemComponent.Get();
}

UAbilitySystemComponent* ACombatCharacterBase::GetAbilitySystemComponent() const
{
	return CombatSystemComponent.Get();
}
