// Fill out your copyright notice in the Description page of Project Settings.


#include "CodePersonAssetManager.h"



UCodePersonAssetManager& UCodePersonAssetManager::Get()
{
	auto* AssetManager{Cast<UCodePersonAssetManager>(GEngine->AssetManager)};
	
	return *AssetManager;
}
