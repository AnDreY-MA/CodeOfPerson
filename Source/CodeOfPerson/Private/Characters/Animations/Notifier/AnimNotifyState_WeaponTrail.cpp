// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Animations/Notifier/AnimNotifyState_WeaponTrail.h"

#include "NiagaraFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(AnimNotifyState_WeaponTrail)

void UAnimNotifyState_WeaponTrail::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                               float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if(!MeshComp || !EffectTemplate) return;

	UE_LOG(LogTemp, Warning, TEXT("TRAIL"));
	
	const FVector Centre = MeshComp->GetSocketLocation(EndSocket) - MeshComp->GetSocketLocation(StartSocket);
	const FVector SpawnLocation = (MeshComp->GetSocketLocation(EndSocket) + MeshComp->GetSocketLocation(StartSocket)) / 2;
	const FRotator Rotation = UKismetMathLibrary::MakeRotFromZ(Centre);
	SpawnedSystem = UNiagaraFunctionLibrary::SpawnSystemAttached(EffectTemplate, MeshComp, AttachPointName, SpawnLocation, Rotation, LocationType, bAutoDestroy, bAutoActivate, PoolingMethod, bPreCullCheck);
	if(!SpawnedSystem) return;
	
	UE_LOG(LogTemp, Warning, TEXT("TRAIL"));
	
	SpawnedSystem->SetFloatParameter(WidthParameter, UKismetMathLibrary::VSize(Centre));
}

void UAnimNotifyState_WeaponTrail::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if(SpawnedSystem)
	{
		SpawnedSystem->DestroyInstance();
	}
}
