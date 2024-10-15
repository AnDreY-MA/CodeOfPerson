// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "CommonInputSubsystem.h"
#include "GameplayEffectTypes.h"
#include "ModularsActors/ModularPlayerController.h"
#include "GenericTeamAgentInterface.h"
#include "PlayerControllerBase.generated.h"

class ACodePersonCharacter;
class URoundWidget;

UCLASS()
class CODEOFPERSON_API APlayerControllerBase : public AModularPlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	explicit APlayerControllerBase(const FObjectInitializer& InObjectInitializer = FObjectInitializer::Get());

	virtual FGenericTeamId GetGenericTeamId() const override
	{
		return FGenericTeamId(0);
	}

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

private:
	void OnHealthChanged(const FOnAttributeChangeData& OnAttributeChangeData);

private:
	UPROPERTY()
	TObjectPtr<ACodePersonCharacter> PlayerCharacter;
	UPROPERTY(EditDefaultsOnly, Category="Health")
	FGameplayAttribute HealthAttribute;
	UPROPERTY(Transient)
	TObjectPtr<UCommonInputSubsystem> InputSubsystem;
};