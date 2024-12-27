// Fill out your copyright notice in the Description page of Project Settings.


#include "UMG/Widgets/RoundWidget.h"

#include "Components/Image.h"
#include "Kismet/KismetMaterialLibrary.h"

void URoundWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetPercent(1.f);
	
}

void URoundWidget::SetPercent(const float InValue)
{
	if(!IsValid(RoundBarMaterial))
	{
		RoundBarMaterial = UKismetMaterialLibrary::CreateDynamicMaterialInstance(GetWorld(), ParentMaterial);
		BarImage->SetBrushFromMaterial(RoundBarMaterial);
	}
	
	RoundBarMaterial->SetScalarParameterValue(ParameterName, InValue);
	
}
