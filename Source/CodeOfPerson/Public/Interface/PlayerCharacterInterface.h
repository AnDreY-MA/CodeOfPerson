// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PlayerCharacterInterface.generated.h"

UINTERFACE(MinimalAPI)
class UPlayerCharacterInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CODEOFPERSON_API IPlayerCharacterInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Player Character Interface")
	void SetCanJump(const bool inValue);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Player Character Interface")
	const bool IsCanJump() const;

};