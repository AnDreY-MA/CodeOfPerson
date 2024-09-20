// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS(Blueprintable, BlueprintType, Abstract)
class CODEOFPERSON_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	explicit ASpawner(const FObjectInitializer& InInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Spawner")
	void Spawn();

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawner|Data", meta = (AllowPrivateAccess = "true"))
	TSoftClassPtr<ACharacter> SpawnCharacter;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawner|Data", meta = (AllowPrivateAccess = "true"))
	bool bSpawnBegin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawner|Data", meta = (AllowPrivateAccess = "true"))
	int32 Count;
	
};