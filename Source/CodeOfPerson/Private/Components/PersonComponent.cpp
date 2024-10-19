// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/PersonComponent.h"
#include <Engine/AssetManager.h>
#include "Components/CombatSystemComponent.h"
#include <Data/PersonData.h>
#include "Characters/CharacterBase.h"

UPersonComponent::UPersonComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UPersonComponent::BeginPlay()
{
	Super::BeginPlay();

	auto* Controller{ Cast<APlayerController>(GetOwner()) };
	if (!Controller) return;
	PlayerCharacter = Controller->GetCharacter();
	check(PlayerCharacter.IsValid());

	SwitchPerson(CurrentPerson);
	
}

void UPersonComponent::SwitchPerson(const FGameplayTag& InPersonTag)
{
	if (UAssetManager* Manager{ UAssetManager::GetIfValid() }; Manager)
	{
		FPrimaryAssetId AssetId = *PersonsMap.Find(InPersonTag);
		auto& Streamable = Manager->GetStreamableManager();
		UPersonData* Data = Manager->GetPrimaryAssetObject<UPersonData>(AssetId);
		if (!IsValid(Data))
		{
			UE_LOG(LogTemp, Warning, TEXT("UPersonComponent: Data is not valid"));
			return;
		}
		FStreamableDelegate TableDelegate;
		const FSoftObjectPath TablePath{ Data->GetActionTable()};
		TableDelegate.BindUObject(this, &UPersonComponent::TableLoaded, TablePath);
		Streamable.RequestAsyncLoad(TablePath, TableDelegate);

		FStreamableDelegate MeshDelegate;
		const FSoftObjectPath MeshPath{ Data->GetSkeletalMesh() };
		MeshDelegate.BindUObject(this, &UPersonComponent::MeshLoaded, MeshPath);
		Streamable.RequestAsyncLoad(MeshPath, MeshDelegate);

		CurrentPerson = InPersonTag;
	}
}

void UPersonComponent::TableLoaded(FSoftObjectPath InPath)
{
	FSoftObjectPtr TablePtr = FSoftObjectPtr(InPath);
	UObject* TableObject{ TablePtr.Get() };
	if (!TableObject)
	{
		UE_LOG(LogTemp, Warning, TEXT("UPersonComponent: TableObject is not valid"));
		return;
	}

	if (auto* Table{ Cast<UDataTable>(TableObject) }; Table)
	{
		auto* CombatComponent{ PlayerCharacter->FindComponentByClass<UCombatSystemComponent>() };
		CombatComponent->UpdateTableAction(Table);
		UE_LOG(LogTemp, Display, TEXT("Switch Table is Success"));
		
	}
}

void UPersonComponent::MeshLoaded(FSoftObjectPath InPath)
{
	FSoftObjectPtr MeshPtr = FSoftObjectPtr(InPath);
	UObject* MeshObject{ MeshPtr.Get() };
	if (!MeshObject)
	{
		UE_LOG(LogTemp, Warning, TEXT("UPersonComponent: TableObject is not valid"));
		return;
	}
	if (auto* Mesh{ Cast<USkeletalMesh>(MeshObject) }; Mesh)
	{
		PlayerCharacter->GetMesh()->SetSkeletalMesh(Mesh);
		UE_LOG(LogTemp, Display, TEXT("Switch Mesh is Success"));

	}
}
