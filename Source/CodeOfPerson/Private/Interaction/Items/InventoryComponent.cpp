// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/Items/InventoryComponent.h"

UInventoryComponent::UInventoryComponent(const FObjectInitializer& InObjectInitializer) :
	Super(InObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.SetTickFunctionEnable(false);
}

void UInventoryComponent::AddKeyItemName(const FGameplayTag& InKeyItemName)
{
	KeyItemName = InKeyItemName;
}

void UInventoryComponent::RemoveItem(const FGameplayTag& InItemTag)
{
	if(KeyItemName == InItemTag)
	{
		KeyItemName = FGameplayTag();
	}
}

void UInventoryComponent::AddItem(const FGameplayTag& InItemTag, const int32 inAmount)
{
	Items.Add(InItemTag, inAmount);
}
