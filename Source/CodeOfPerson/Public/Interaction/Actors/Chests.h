// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chests.generated.h"

UCLASS(Blueprintable, Abstract)
class CODEOFPERSON_API AChests : public AActor
{
	GENERATED_BODY()
	
public:	
	explicit AChests(const FObjectInitializer& InObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Chests")
	void Open();

private:
	UPROPERTY(BlueprintReadWrite, Category = "Chests", meta = (AllowPrivateAccess="true"))
	bool bOpened{ false };

};