// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InventoryComponentInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInventoryComponentInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CODEOFPERSON_API IInventoryComponentInterface
{
	GENERATED_BODY()

	
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Inventory Component Interface")
	class UInventoryComponent* GetInventoryComponent() const;

};