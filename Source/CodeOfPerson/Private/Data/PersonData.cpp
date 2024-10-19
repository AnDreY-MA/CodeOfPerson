// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/PersonData.h"


UPersonData::UPersonData(const FObjectInitializer& InInitializer)
	: Super(InInitializer)
{
}

FPrimaryAssetId UPersonData::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(Type, GetFName());
}