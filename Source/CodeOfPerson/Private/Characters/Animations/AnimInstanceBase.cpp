// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/Animations/AnimInstanceBase.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Runtime/AnimGraphRuntime/Public/KismetAnimationLibrary.h"

FAnimInstanceProxyBase::FAnimInstanceProxyBase() :
	MovementSpeed(0.f), Velocity(FVector::ZeroVector), Direction(0.f), bFalling(false)
{
}

void FAnimInstanceProxyBase::Initialize(UAnimInstance* InAnimInstance)
{
	FAnimInstanceProxy::Initialize(InAnimInstance);

	OwningCharacter = Cast<ACharacter>(InAnimInstance->TryGetPawnOwner());
	
}

void FAnimInstanceProxyBase::PreUpdate(UAnimInstance* InAnimInstance, float DeltaSeconds)
{
	FAnimInstanceProxy::PreUpdate(InAnimInstance, DeltaSeconds);

	if(!ensureAlways(InAnimInstance))
	{
		return;
	}

	UpdateMovement();
	UpdateDirectionMovement();
	
}

void FAnimInstanceProxyBase::UpdateMovement()
{
	if (!OwningCharacter) return;

	Velocity = OwningCharacter->GetVelocity();
	MovementSpeed = UKismetMathLibrary::VSizeXY(Velocity);
	bFalling = OwningCharacter->GetCharacterMovement()->IsFalling();

}

void FAnimInstanceProxyBase::UpdateDirectionMovement()
{
	if (!OwningCharacter) return;

	Direction = UKismetAnimationLibrary::CalculateDirection(FVector(Velocity.X, Velocity.Y, 0.0), OwningCharacter->GetActorRotation());
	Direction = UKismetMathLibrary::NormalizeAxis(Direction);

}

void UAnimInstanceBase::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	Proxy.Initialize(this);

}