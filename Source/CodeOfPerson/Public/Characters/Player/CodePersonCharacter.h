// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "CommonInputSubsystem.h"
#include "InputActionValue.h"
#include "Characters/CharacterBase.h"
#include "Interfaces/CombatWarpComponentInterface.h"
#include "Interface/InventoryComponentInterface.h"
#include "Interface/PlayerCharacterInterface.h"
#include "Interfaces/CombatComponentInterface.h"
#include "AbilitySystemInterface.h"
#include "CodePersonCharacter.generated.h"

class URoundWidget;
class UWidgetComponent;
class UCameraControlComponent;
class UCombatWarpingComponent;
class UCameraComponent;
class USpringArmComponent;
class UCombatSystemComponent;

UCLASS(Blueprintable, Abstract)
class ACodePersonCharacter : public ACharacterBase, public ICombatWarpComponentInterface, public IInventoryComponentInterface, public IPlayerCharacterInterface,
	public ICombatComponentInterface, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	explicit ACodePersonCharacter(const FObjectInitializer& InInitializer = FObjectInitializer::Get());

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
	FORCEINLINE UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }

	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	//ICombatWarpComponentInterface Implementation

	virtual UCombatWarpingComponent* GetCombatWarpingComponent_Implementation() const override;

	// IPlayerCharacterInterface Implementation

	void SetCanJump_Implementation(const bool InValue)
	{
		bCanJumpCustom = InValue;
	}

	const bool IsCanJump_Implementation() const
	{
		return bCanJumpCustom;
	}

	// IPlayerCharacterInterface


	// ICombatComponentInterface Implementation
	UCombatSystemComponent* GetCombatSystemComponent_Implementation() const
	{
		return CombatComponent.Get();
	}
	// End ICombatComponentInterface

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

private:
	UFUNCTION(BlueprintCallable, Category="Movement")
	void Move(const FInputActionValue& Value);

	void CheckJumpHeigth();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> TopDownCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCombatWarpingComponent> CombatWarping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCombatSystemComponent> CombatComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UWidgetComponent> HealthBarComponent;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCameraControlComponent> CameraControlComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="HealtWidget", meta=(AllowPrivateAccess="true"))
	TObjectPtr<URoundWidget> HealthBarWidget;

	UPROPERTY(EditDefaultsOnly, Category = "Movement|Jump")
	double DistanceCkeckJump;
	UPROPERTY(EditDefaultsOnly, Category = "Movement|Jump")
	double HeigthJump;
	UPROPERTY(EditDefaultsOnly, Category = "Movement|Jump")
	double MinSpeedJump;
	UPROPERTY(EditDefaultsOnly, Category = "Movement|Jump")
	TEnumAsByte<ETraceTypeQuery> CheckJumpTraceType;
	/*UPROPERTY(EditDefaultsOnly, Category = "Movement|Jump")
	TEnumAsByte<EDrawDebugTrace::Type> CheckJumpDebug;*/

	UPROPERTY()
	bool bCanJumpCustom{ true };

	friend class APlayerControllerBase;
	
};
