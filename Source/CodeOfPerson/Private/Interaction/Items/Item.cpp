// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/Items/Item.h"

#include "Characters/Player/CodePersonCharacter.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	SetRootComponent(StaticMesh);
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	BoxCollision->SetupAttachment(StaticMesh);
	
	
	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>("Interact Widget");
	WidgetComponent->SetupAttachment(StaticMesh);
	WidgetComponent->SetVisibility(false);

}

void AItem::BeginPlay()	
{
	Super::BeginPlay();

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnBeginOverlaped);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &AItem::OnEndOverlaped);
}

void AItem::OnBeginOverlaped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor->IsA(ACodePersonCharacter::StaticClass()))
	{
		WidgetComponent->SetVisibility(true);
	}
	
}

void AItem::OnEndOverlaped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if(OtherActor->IsA(ACodePersonCharacter::StaticClass()))
	{
		WidgetComponent->SetVisibility(false);
	}
	
}