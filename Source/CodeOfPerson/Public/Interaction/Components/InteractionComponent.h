// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"


class AGrabableActor;

UCLASS(meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType)
class CODEOFPERSON_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	explicit UInteractionComponent(const FObjectInitializer& InInitializer = FObjectInitializer::Get());

	void Grab(AGrabableActor* InGrabActor);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(BlueprintReadWrite, Category="Interaction|Grab", meta=(AllowPrivateAccess=true))
	TObjectPtr<AGrabableActor> GrabableActor;
	

};
