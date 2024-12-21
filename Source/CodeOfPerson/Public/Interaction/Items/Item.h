// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"

#include "Interaction/InteractionInterface.h"
#include "Item.generated.h"

class UBoxComponent;
class UWidgetComponent;

UCLASS(Blueprintable, BlueprintType, Abstract)
class CODEOFPERSON_API AItem : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:
	explicit AItem(const FObjectInitializer& InInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> StaticMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UWidgetComponent> WidgetComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data", meta = (AllowPrivateAccess = "true"))
	FGameplayTag ItemName;

};