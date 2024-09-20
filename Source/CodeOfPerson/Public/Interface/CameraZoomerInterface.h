// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CameraZoomerInterface.generated.h"

UINTERFACE(Blueprintable, BlueprintType, MinimalAPI)
class UCameraZoomerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CODEOFPERSON_API ICameraZoomerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Camera Zoomer Interface")
	const float GetTargetOffset() const;
	
};
