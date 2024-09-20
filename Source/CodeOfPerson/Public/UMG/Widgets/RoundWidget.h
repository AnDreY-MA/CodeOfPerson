// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RoundWidget.generated.h"

class UImage;
class UMaterialInstanceDynamic;
class UMaterialInterface;

UCLASS(Abstract)
class CODEOFPERSON_API URoundWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	
	UFUNCTION(BlueprintCallable)
	void SetPercent(const float InValue);

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RoundBar", meta=(BindWidget, AllowPrivateAccess="true"))
	TObjectPtr<UImage> BarImage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="RoundBar", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UMaterialInstanceDynamic> RoundBarMaterial;

	UPROPERTY(EditDefaultsOnly, Category="RoundBar")
	TObjectPtr<UMaterialInterface> ParentMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RoundBar", meta=(AllowPrivateAccess="true"))
	FName ParameterName;
	
};
