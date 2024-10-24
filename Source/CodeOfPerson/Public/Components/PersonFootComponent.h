// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <GameplayTagContainer.h>
#include "PersonFootComponent.generated.h"

class USoundBase;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CODEOFPERSON_API UPersonFootComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	explicit UPersonFootComponent(const FObjectInitializer& InInitializer = FObjectInitializer::Get());

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "FootSteps")
	TMap<FGameplayTag, USoundBase*> StepsMap;

};