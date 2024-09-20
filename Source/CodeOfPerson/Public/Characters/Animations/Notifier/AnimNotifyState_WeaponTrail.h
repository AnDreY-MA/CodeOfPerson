// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraComponent.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "AnimNotifyState_WeaponTrail.generated.h"

class UNiagaraSystem;

UCLASS()
class CODEOFPERSON_API UAnimNotifyState_WeaponTrail : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;

	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

private:
	UPROPERTY(EditAnywhere, Category="Effect")
	TObjectPtr<UNiagaraSystem> EffectTemplate;
	UPROPERTY(EditAnywhere, Category="Effect")
	FName AttachPointName{NAME_None};
	UPROPERTY(EditAnywhere, Category="Effect")
	TEnumAsByte<EAttachLocation::Type> LocationType;
	UPROPERTY(EditAnywhere, Category="Effect")
	bool bAutoDestroy;
	UPROPERTY(EditAnywhere, Category="Effect")
	bool bAutoActivate;
	UPROPERTY(EditAnywhere, Category="Effect")
	bool bPreCullCheck;
	UPROPERTY(EditAnywhere, Category="Effect")
	ENCPoolMethod PoolingMethod;
	UPROPERTY(EditAnywhere, Category="Effect")
	FName StartSocket;
	UPROPERTY(EditAnywhere, Category="Effect")
	FName EndSocket;
	UPROPERTY(EditAnywhere, Category="Effect")
	FName WidthParameter;
	
	UPROPERTY()
	TObjectPtr<UNiagaraComponent> SpawnedSystem;
};