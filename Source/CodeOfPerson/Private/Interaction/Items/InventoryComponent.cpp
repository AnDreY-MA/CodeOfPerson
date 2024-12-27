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

void UInventoryComponent::RemoveItem(const FGameplayTag& InItemTag, const int32 inAmount)
{
	if (Items.Contains(InItemTag))
	{
		const int32 Result = *Items.Find(InItemTag) - inAmount;
		if (Result == 0)
		{
			Items.Remove(InItemTag);
		}
		else { Items[InItemTag] = inAmount; }

		if (OnItemRemoved.IsBound())
		{
			OnItemRemoved.Broadcast(InItemTag, inAmount);
		}
		if (OnItemsUpdated.IsBound())
		{
			OnItemsUpdated.Broadcast(InItemTag, inAmount);
		}
	}

}

void UInventoryComponent::AddItem(const FGameplayTag& InItemTag, const int32 inAmount)
{
	if (Items.Contains(InItemTag))
	{
		*Items.Find(InItemTag) += inAmount;
	}
	else
	{
		Items.Add(InItemTag, inAmount);
	}
	if (OnItemAdded.IsBound())
	{
		OnItemAdded.Broadcast(InItemTag, inAmount);
	}
	if (OnItemsUpdated.IsBound())
	{
		OnItemsUpdated.Broadcast(InItemTag, *Items.Find(InItemTag));
	}
	
}