// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstanceProxy.h"
#include "Animation/CombatAnimInstance.h"
#include "AnimInstanceBase.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct FAnimInstanceProxyBase : public FAnimInstanceProxy
{
	GENERATED_BODY()

	FAnimInstanceProxyBase();

	UPROPERTY(Transient, VisibleAnywhere, BlueprintReadOnly, Category="Proxy|Movement", meta=(AllowPrivateAccess="true"))
	double MovementSpeed;
	
	UPROPERTY(Transient, VisibleAnywhere, BlueprintReadOnly, Category="Proxy|Movement", meta=(AllowPrivateAccess="true"))
	FVector Velocity;

	UPROPERTY(Transient, VisibleAnywhere, BlueprintReadOnly, Category = "Proxy|Movement", meta = (AllowPrivateAccess = "true"))
	float Direction;

	UPROPERTY(Transient, VisibleAnywhere, BlueprintReadOnly, Category="Proxy|Movement", meta=(AllowPrivateAccess="true"))
	bool bFalling;

	virtual void Initialize(UAnimInstance* InAnimInstance) override;

protected:

	virtual void PreUpdate(UAnimInstance* InAnimInstance, float DeltaSeconds) override;

private:
	UPROPERTY(Transient, VisibleAnywhere, BlueprintReadOnly, Category = "Proxy", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class ACharacter> OwningCharacter;

	void UpdateMovement();
	void UpdateDirectionMovement();
	
};

UCLASS(Abstract)
class CODEOFPERSON_API UAnimInstanceBase : public UCombatAnimInstance
{
	GENERATED_BODY()

protected:
	virtual FAnimInstanceProxy* CreateAnimInstanceProxy() override
	{
		return &Proxy;
	}

	virtual void DestroyAnimInstanceProxy(FAnimInstanceProxy* InProxy) override
	{
		
	}

	virtual void NativeBeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Proxy", meta=(AllowPrivateAccess="true"))
	FAnimInstanceProxyBase Proxy;


	friend struct FAnimInstanceProxyBase;
};
