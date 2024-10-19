// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PushComponent.generated.h"

class APushableObject;


UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class CODEOFPERSON_API UPushComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	explicit UPushComponent();

	UFUNCTION(BlueprintCallable)
	void BeginPush(APushableObject* InObject);

	UFUNCTION(BlueprintCallable)
	void EndPush();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

};
