// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <GameplayTagContainer.h>

#include "PersonComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPersonChanged, const FGameplayTag, OutPerson);

class UPersonData;

UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent) )
class CODEOFPERSON_API UPersonComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	explicit UPersonComponent(const FObjectInitializer& InInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable)
	void SwitchPerson(const FGameplayTag& InPersonTag);

	UPROPERTY(BlueprintAssignable, Category = "Persons")
	FOnPersonChanged OnPersonChanged;

protected:
	virtual void BeginPlay() override;

private:
	void TableLoaded(FSoftObjectPath InPath);
	void MeshLoaded(FSoftObjectPath InPath, FGameplayTag InPersonTag);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Persons")
	TMap<FGameplayTag, UPersonData*> PersonsMap;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Persons", meta = (AllowPrivateAccess=true))
	FGameplayTag CurrentPerson;
		
	UPROPERTY()
	TWeakObjectPtr<class ACharacter> PlayerCharacter;

};