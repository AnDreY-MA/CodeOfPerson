// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/DeathAbility.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(DeathAbility)

void UDeathAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	ActorInfo->AvatarActor->SetLifeSpan(0.05f);
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, false, false);

}
