// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include <GameplayTagContainer.h>
#include "PersonAnimInstanceInterface.generated.h"

UINTERFACE(MinimalAPI)
class UPersonAnimInstanceInterface : public UInterface
{
	GENERATED_BODY()
};


class CODEOFPERSON_API IPersonAnimInstanceInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Person AnimInstance Interface")
	void SwitchPerson(const FGameplayTag& InPerson);

};