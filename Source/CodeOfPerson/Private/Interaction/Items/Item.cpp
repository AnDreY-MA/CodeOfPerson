// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/Items/Item.h"

#include "Characters/Player/CodePersonCharacter.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(Item)

AItem::AItem(const FObjectInitializer& InInitializer) :
	Super(InInitializer)
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	SetRootComponent(StaticMesh);
	
	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>("Interact Widget");
	WidgetComponent->SetupAttachment(StaticMesh);
	WidgetComponent->SetVisibility(false);


}
