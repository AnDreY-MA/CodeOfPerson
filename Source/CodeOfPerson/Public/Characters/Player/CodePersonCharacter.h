// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "CommonInputSubsystem.h"
#include "InputActionValue.h"
#include "Characters/CharacterBase.h"
#include "Interfaces/CombatWarpComponentInterface.h"
#include "CodePersonCharacter.generated.h"

class URoundWidget;
class UWidgetComponent;
class UCameraControlComponent;
class UCombatWarpingComponent;
class UCameraComponent;
class USpringArmComponent;

UCLASS(Blueprintable, Abstract)
class ACodePersonCharacter : public ACharacterBase, public ICombatWarpComponentInterface
{
	GENERATED_BODY()

public:
	explicit ACodePersonCharacter(const FObjectInitializer& InInitializer = FObjectInitializer::Get());

	virtual void BeginPlay() override;
	
	FORCEINLINE UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }

	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	//ICombatWarpComponentInterface Implementation

	FORCEINLINE virtual UCombatWarpingComponent* GetCombatWarpingComponent_Implementation() const override
	{
		return CombatWarpingComponent.Get();
	}

private:
	UFUNCTION(BlueprintCallable, Category="Movement")
	void Move(const FInputActionValue& Value);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> TopDownCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	TObjectPtr<UCombatWarpingComponent> CombatWarpingComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UWidgetComponent> HealthBarComponent;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCameraControlComponent> CameraControlComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="HealtWidget", meta=(AllowPrivateAccess="true"))
	TObjectPtr<URoundWidget> HealthBarWidget;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Input", meta=(AllowPrivateAccess="true"))
	ECommonInputType InputType;

	friend class APlayerControllerBase;
	
};