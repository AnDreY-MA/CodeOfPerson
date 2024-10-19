// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "MontageBlendoutNotifyState.generated.h"

UENUM(BlueprintType)
enum class EBlendOutCondition : uint8
{
	MovementInput = 0,
	ForceBlendOut,
	IfFalling
};

UCLASS()
class CODEOFPERSON_API UMontageBlendoutNotifyState : public UAnimNotifyState
{
	GENERATED_BODY()
	
public:
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference);

private:
	UPROPERTY(EditAnywhere)
	EBlendOutCondition Condition;

	UPROPERTY(EditAnywhere)
	float BlendOutTime{ 0.2f };
};
