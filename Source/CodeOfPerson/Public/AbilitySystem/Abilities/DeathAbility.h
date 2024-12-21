// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "DeathAbility.generated.h"

class ALootActor;

UCLASS(Blueprintable)
class CODEOFPERSON_API UDeathAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, 
		const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Loot", meta = (AllowPrivateAccess=true))
	TSoftClassPtr<ALootActor> LootActorClass;
	
};
