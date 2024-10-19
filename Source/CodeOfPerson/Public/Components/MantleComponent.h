// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MantleComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CODEOFPERSON_API UMantleComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	explicit UMantleComponent();

protected:
	virtual void BeginPlay() override;


		
};
