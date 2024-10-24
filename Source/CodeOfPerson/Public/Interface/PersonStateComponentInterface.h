// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PersonStateComponentInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPersonStateComponentInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CODEOFPERSON_API IPersonStateComponentInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Person State Component Interface")
	class UPersonComponent* GetPersonComponent() const;

};