// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PushableObject.generated.h"

UCLASS()
class CODEOFPERSON_API APushableObject : public AActor
{
	GENERATED_BODY()
	
public:	
	explicit APushableObject();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	int32 FindClosestPushTransformIndex(const FVector2D& InInstigatorLocation, const float InPushRange);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Push", meta = (AllowPrivateAccess=true, MakeEditWidget))
	TArray<FTransform> PushTransform;

};