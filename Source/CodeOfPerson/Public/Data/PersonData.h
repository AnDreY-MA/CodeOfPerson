// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PersonData.generated.h"

/**
 * 
 */
UCLASS()
class CODEOFPERSON_API UPersonData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	explicit UPersonData(const FObjectInitializer& InInitializer = FObjectInitializer::Get());

	virtual FPrimaryAssetId GetPrimaryAssetId() const override;

	FORCEINLINE FSoftObjectPath GetActionTable() const
	{
		return ActionTable.ToSoftObjectPath();
	}

	FORCEINLINE FSoftObjectPath GetSkeletalMesh() const
	{
		return Mesh.ToSoftObjectPath();
	}
	
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PersonData", meta = (AllowPrivateAccess = "true"))
	FPrimaryAssetType Type;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PersonData", meta = (AssetBundles="SoftData", AllowPrivateAccess="true"))
	TSoftObjectPtr<UDataTable> ActionTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PersonData", meta = (AssetBundles = "SoftData", AllowPrivateAccess = "true"))
	TSoftObjectPtr<USkeletalMesh> Mesh;

};