// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemsUpdated, const FGameplayTag&, Item, int32, Count);

UCLASS(meta=(BlueprintSpawnableComponent))
class CODEOFPERSON_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	explicit UInventoryComponent(const FObjectInitializer& InObjectInitializer = FObjectInitializer::Get());

	UPROPERTY(BlueprintAssignable)
	FOnItemsUpdated OnItemAdded;
	UPROPERTY(BlueprintAssignable)
	FOnItemsUpdated OnItemRemoved;

	UFUNCTION(BlueprintCallable)
	void AddKeyItemName(const FGameplayTag& InKeyItemName);

	UFUNCTION(BlueprintCallable)
	void RemoveItem(const FGameplayTag& InItemTag, const int32 inAmount = 1);

	UFUNCTION(BlueprintCallable)
	void AddItem(const FGameplayTag& InItemTag, const int32 inAmount = 1);

	UFUNCTION(BlueprintCallable)
	FORCEINLINE FGameplayTag GetKeyItem() const
		{
		return KeyItemName;
	}
	UFUNCTION(BlueprintPure)
	bool HasItem(const FGameplayTag& InItem)
	{
		return Items.Contains(InItem);
	}

private:
	UPROPERTY()
	FGameplayTag KeyItemName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory", meta = (AllowPrivateAccess = true))
	TMap<FGameplayTag, int32> Items;
		
};