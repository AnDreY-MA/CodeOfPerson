// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CODEOFPERSON_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	explicit UInventoryComponent();

	UFUNCTION(BlueprintCallable)
	void AddKeyItemName(const FGameplayTag& InKeyItemName);

	UFUNCTION(BlueprintCallable)
	void RemoveItem(const FGameplayTag& InItemTag);

	UFUNCTION(BlueprintCallable)
	FORCEINLINE FGameplayTag GetKeyItem() const
		{
		return KeyItemName;
	}

private:
	UPROPERTY()
	FGameplayTag KeyItemName;
		
};
