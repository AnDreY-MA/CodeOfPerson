// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CameraControlComponent.generated.h"


class USpringArmComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CODEOFPERSON_API UCameraControlComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	explicit UCameraControlComponent(const FObjectInitializer& InInitializer = FObjectInitializer::Get());

protected:
	virtual void BeginPlay() override;

private:

	UFUNCTION()
	void OnStartZoom(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnRevertZoom(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void UpdateZoomIn();
	UFUNCTION()
	void UpdateZoomOut();

private:
	UPROPERTY(EditDefaultsOnly, Category="Zooming")
	double ZoomStep;
	UPROPERTY(EditDefaultsOnly, Category="Zooming")
	double ZoomMultiplier;
	UPROPERTY(EditDefaultsOnly, Category="Zooming")
	double TargetSocketOffset;

	UPROPERTY(EditDefaultsOnly, Category="Zooming")
	double InterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Zooming")
	float TimeStep;

	UPROPERTY(EditDefaultsOnly, Category="Zooming")
	TSoftClassPtr<AActor> ActorTriggerClass;

	UPROPERTY()
	TWeakObjectPtr<USpringArmComponent> SpringArmComponent;
	
	UPROPERTY()
	FTimerHandle TimerHandle;
	UPROPERTY()
	float DefaultArmLength;
	
};