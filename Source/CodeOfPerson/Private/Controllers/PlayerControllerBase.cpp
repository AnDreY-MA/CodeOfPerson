// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/PlayerControllerBase.h"

#include "AbilitySystemComponent.h"
#include "CommonInputSubsystem.h"
#include "Characters/Player/CodePersonCharacter.h"
#include "UMG/Widgets/RoundWidget.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(PlayerControllerBase)

APlayerControllerBase::APlayerControllerBase(const FObjectInitializer& InObjectInitializer) :
	Super(InObjectInitializer), PlayerCharacter(nullptr)
{
}

void APlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = Cast<ACodePersonCharacter>(GetPawn());

	if (auto* AbilityComponent{PlayerCharacter->FindComponentByClass<UAbilitySystemComponent>()}; AbilityComponent)
	{
		AbilityComponent->GetGameplayAttributeValueChangeDelegate(HealthAttribute).AddUObject(
			this, &APlayerControllerBase::OnHealthChanged);
	}

	//FInputModeGameOnly InputMode;
	//SetInputMode(InputMode/*InputMode.SetConsumeCaptureMouseDown(false)*/);
}

void APlayerControllerBase::OnHealthChanged(const FOnAttributeChangeData& OnAttributeChangeData)
{
	if (!PlayerCharacter->HealthBarWidget)
	{
		UE_LOG(LogTemp, Warning, TEXT("HealthBarWidget is NULL"));
		return;
	}

	const float CurrentValue{OnAttributeChangeData.NewValue};
	PlayerCharacter->HealthBarWidget->SetPercent(CurrentValue * 0.01f);

	if (CurrentValue == 0.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Is Dead"));
	}
}
