// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <GameplayTagContainer.h>

#include "PersonComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent) )
class CODEOFPERSON_API UPersonComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	explicit UPersonComponent();

	UFUNCTION(BlueprintCallable)
	void SwitchPerson(const FGameplayTag& InPersonTag);

protected:
	virtual void BeginPlay() override;

private:
	void TableLoaded(FSoftObjectPath InPath);
	void MeshLoaded(FSoftObjectPath InPath);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Persons")
	TMap<FGameplayTag, FPrimaryAssetId> PersonsMap;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Persons", meta = (AllowPrivateAccess=true))
	FGameplayTag CurrentPerson;

	UPROPERTY()
	TWeakObjectPtr<class ACharacter> PlayerCharacter;

};