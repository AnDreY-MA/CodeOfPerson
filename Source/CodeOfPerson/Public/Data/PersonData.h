// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Components/DataAbilitySystemComponent.h"
#include "PersonData.generated.h"


UCLASS()
class CODEOFPERSON_API UPersonData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	explicit UPersonData(const FObjectInitializer& InInitializer = FObjectInitializer::Get());

	virtual FPrimaryAssetId GetPrimaryAssetId() const override;

	FORCEINLINE FSoftObjectPath GetActionTableSoft() const
	{
		return ActionTableSoft.ToSoftObjectPath();
	}

	FORCEINLINE FSoftObjectPath GetSkeletalMeshSoft() const
	{
		return MeshSoft.ToSoftObjectPath();
	}

	FORCEINLINE UDataTable* GetActionTable() const
	{
		return ActionTable;
	}

	FORCEINLINE USkeletalMesh* GetSkeletalMesh() const
	{
		return Mesh;
	}

	FORCEINLINE FCombatAttributeData GetAttribute()
	{
		return AttributeData;
	}
	
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PersonData", meta = (AllowPrivateAccess = "true"))
	FPrimaryAssetType Type;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PersonData", meta = (AssetBundles="SoftData", AllowPrivateAccess="true"))
	TSoftObjectPtr<UDataTable> ActionTableSoft;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PersonData", meta = (AssetBundles = "SoftData", AllowPrivateAccess = "true"))
	TSoftObjectPtr<USkeletalMesh> MeshSoft;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PersonData", meta = (AssetBundles = "Data", AllowPrivateAccess = "true"))
	TObjectPtr<UDataTable> ActionTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PersonData", meta = (AssetBundles = "Data", AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMesh> Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PersonData", meta = (AssetBundles = "Data", AllowPrivateAccess = "true"))
	FCombatAttributeData AttributeData;


};