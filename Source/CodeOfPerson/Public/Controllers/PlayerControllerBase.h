// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "CommonInputSubsystem.h"
#include "GameplayEffectTypes.h"
#include "ModularsActors/ModularPlayerController.h"
#include "PlayerControllerBase.generated.h"

class ACodePersonCharacter;
class URoundWidget;

UCLASS()
class CODEOFPERSON_API APlayerControllerBase : public AModularPlayerController
{
	GENERATED_BODY()

public:
	explicit APlayerControllerBase(const FObjectInitializer& InObjectInitializer = FObjectInitializer::Get());

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