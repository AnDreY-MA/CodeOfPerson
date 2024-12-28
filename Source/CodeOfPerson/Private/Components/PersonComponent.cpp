// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/PersonComponent.h"
#include <Engine/AssetManager.h>
#include "Components/CombatSystemComponent.h"
#include <Data/PersonData.h>
#include "Characters/CharacterBase.h"
#include <ranges>
#include <Interface/PersonAnimInstanceInterface.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(PersonComponent)

UPersonComponent::UPersonComponent(const FObjectInitializer& InInitializer) :
	Super(InInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UPersonComponent::BeginPlay()
{
	Super::BeginPlay();

	auto* Controller{ Cast<APlayerController>(GetOwner()) };
	if (!Controller) return;
	PlayerCharacter = Controller->GetCharacter();
	
}

void UPersonComponent::SwitchPersonSync(const FGameplayTag& InPersonTag)
{
	if (CurrentPerson == InPersonTag)
	{
		UE_LOG(LogTemp, Warning, TEXT("PersonComponent: same person tags"));
		return;
	}

	UPersonData* Data = *PersonsMap.Find(InPersonTag);
}

void UPersonComponent::SwitchPerson(const FGameplayTag& InPersonTag)
{
	if (CurrentPerson == InPersonTag)
	{
		UE_LOG(LogTemp, Warning, TEXT("PersonComponent: same person tags"));
		return;
	}

	if (UAssetManager* Manager{ UAssetManager::GetIfValid() }; Manager)
	{
		UPersonData* Data = *PersonsMap.Find(InPersonTag);
		auto& Streamable = Manager->GetStreamableManager();
		//UPersonData* Data = Manager->GetPrimaryAssetObject<UPersonData>(AssetId);
		if (!IsValid(Data) || !Data->GetActionTableSoft().IsValid() || !Data->GetSkeletalMeshSoft().IsValid())
		{
			UE_LOG(LogTemp, Warning, TEXT("UPersonComponent: Data is not valid"));
			return;
		}
		FStreamableDelegate TableDelegate;
		const FSoftObjectPath TablePath{ Data->GetActionTableSoft()};
		TableDelegate.BindUObject(this, &UPersonComponent::TableLoaded, TablePath);
		Streamable.RequestAsyncLoad(TablePath, TableDelegate);

		FStreamableDelegate MeshDelegate;
		const FSoftObjectPath MeshPath{ Data->GetSkeletalMeshSoft() };
		MeshDelegate.BindUObject(this, &UPersonComponent::MeshLoaded, MeshPath, InPersonTag);
		Streamable.RequestAsyncLoad(MeshPath, MeshDelegate);

		if (auto* CombatComponent{ ICombatComponentInterface::Execute_GetCombatSystemComponent(PlayerCharacter.Get()) }; CombatComponent)
		{
			CombatComponent->RemoveAllSpawnedAttributes();
			CombatComponent->UpdateAttribute({ Data->GetAttribute() });
		}
	}

}

void UPersonComponent::TableLoaded(FSoftObjectPath InPath)
{
	FSoftObjectPtr TablePtr = FSoftObjectPtr(InPath);
	if (!TablePtr.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("UPersonComponent: TablePtr is not valid"));
		return;
	}

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

void UPersonComponent::MeshLoaded(FSoftObjectPath InPath, FGameplayTag InPersonTag)
{
	FSoftObjectPtr MeshPtr = FSoftObjectPtr(InPath);
	UObject* MeshObject{ MeshPtr.Get() };
	if (!MeshObject)
	{
		UE_LOG(LogTemp, Warning, TEXT("UPersonComponent: Mesh is not valid"));
		return;
	}
	if (auto* Mesh{ Cast<USkeletalMesh>(MeshObject) }; Mesh)
	{
		auto* MeshComponent{ PlayerCharacter->GetMesh() };
		TArray<USceneComponent*> ChildComponents;
		MeshComponent->GetChildrenComponents(true, ChildComponents);
		for (auto* Comp : ChildComponents)
		{
			if (Comp->ComponentHasTag("Persons.Aya"))
			{
				Comp->SetVisibility(!Comp->IsVisible());
			}
		}
		MeshComponent->SetSkeletalMesh(Mesh);
		auto* AnimInstance{ MeshComponent->GetAnimInstance() };
		if (AnimInstance->Implements<UPersonAnimInstanceInterface>())
		{
			IPersonAnimInstanceInterface::Execute_SwitchPerson(AnimInstance, InPersonTag);
		}

		CurrentPerson = InPersonTag;
		OnPersonChanged.Broadcast(CurrentPerson);
		UE_LOG(LogTemp, Display, TEXT("Switch Mesh is Success"));

	}

}