// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <Engine/DataAsset.h>
#include "MamontItemData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FPrimaryMamontItemId : public FPrimaryAssetId
{
	GENERATED_BODY()

	FPrimaryMamontItemId() : Super()
	{

	}

	explicit FPrimaryMamontItemId(const FPrimaryAssetId& InId) : Super(InId.PrimaryAssetType, InId.PrimaryAssetName) {}

	explicit FPrimaryMamontItemId(const FString& TypeAndName) : Super(TypeAndName) {}

	bool operator>(const FPrimaryMamontItemId& Other) const
	{
		return ToString() > Other.ToString();
	}

	bool operator<(const FPrimaryMamontItemId& Other) const
	{
		return ToString() < Other.ToString();
	}

};

USTRUCT(BlueprintType)
struct FMamontItemInfo
{
	GENERATED_BODY()

	static const FMamontItemInfo EmptyItemInfo;

	FMamontItemInfo() = default;

	explicit FMamontItemInfo(const FPrimaryMamontItemId& InItemId) : ItemId(InItemId)
	{
	}

	explicit FMamontItemInfo(const FPrimaryMamontItemId& InItemId, const int32& InQuant) : ItemId(InItemId), Quantity(InQuant)
	{
	}

	explicit FMamontItemInfo(const FPrimaryMamontItemId& InItemId, const int32& InQuant,
		const FGameplayTagContainer& InTags) : ItemId(InItemId), Quantity(InQuant), Tags(InTags)
	{
	}

	bool operator==(const FMamontItemInfo& Other) const
	{
		return ItemId == Other.ItemId && Tags == Other.Tags;
	}

	bool operator!=(const FMamontItemInfo& Other) const
	{
		return !(*this == Other);
	}

	bool operator<(const FMamontItemInfo& Other) const
	{
		return ItemId.ToString() < Other.ItemId.ToString();
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mamont Item Info")
	FPrimaryMamontItemId ItemId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mamont Item Info")
	int32 Quantity{1};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mamont Item Info")
	FGameplayTagContainer Tags;
};

UCLASS(NotBlueprintable, NotPlaceable)
class CODEOFPERSON_API UMamontItemData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:

	FORCEINLINE virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId(TEXT("MamontItemData"), *("Item_" + FString::FromInt(ItemId)));
	}

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MamontItemData", meta = (AssetBundles = "Data"))
	int32 ItemId;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mamont Item Data", meta = (AssetBundles = "Data"))
	FName ItemName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mamont Item Data", meta = (AssetBundles = "Data"))
	TMap<FGameplayTag, FPrimaryMamontItemId> Relations;

};