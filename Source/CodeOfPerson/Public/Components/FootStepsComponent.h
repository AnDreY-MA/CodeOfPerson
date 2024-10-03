// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FootStepsComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CODEOFPERSON_API UFootStepsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	explicit UFootStepsComponent(const FObjectInitializer& InInitializer = FObjectInitializer::Get());


		
};
