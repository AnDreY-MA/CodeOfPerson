// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/CameraControlComponent.h"

#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CameraControlComponent)


UCameraControlComponent::UCameraControlComponent(const FObjectInitializer& InInitializer) :
	Super(InInitializer), ZoomStep(625.0), ZoomMultiplier(2.0), TargetSocketOffset(460), InterpSpeed(1.5), TimeStep(0.01), DefaultArmLength(0)
{
	PrimaryComponentTick.bCanEverTick = true;

	

}

void UCameraControlComponent::BeginPlay()
{
	Super::BeginPlay();

	if(auto* Owner {GetOwner()}; Owner)
	{
		Owner->OnActorBeginOverlap.AddDynamic(this, &UCameraControlComponent::OnStartZoom);
		Owner->OnActorEndOverlap.AddDynamic(this, &UCameraControlComponent::OnRevertZoom);

		SpringArmComponent = Owner->FindComponentByClass<USpringArmComponent>();
		DefaultArmLength = SpringArmComponent->TargetArmLength;
	}

}

void UCameraControlComponent::OnStartZoom(AActor* OverlappedActor, AActor* OtherActor)
{
	if(ActorTriggerClass == OtherActor->GetClass())
	{
		UKismetSystemLibrary::K2_ClearTimerHandle(this, TimerHandle);
		FTimerDynamicDelegate StartDelegate;
		StartDelegate.BindDynamic(this, &UCameraControlComponent::UpdateZoomOut);
		//GetWorld()->GetTimerManager().SetTimer(TimerHandle, StartDelegate, TimeStep, true);
		TimerHandle = UKismetSystemLibrary::K2_SetTimerDelegate(StartDelegate, TimeStep, true, true);

	}
	
}

void UCameraControlComponent::OnRevertZoom(AActor* OverlappedActor, AActor* OtherActor)
{
	if(ActorTriggerClass == OtherActor->GetClass())
	{
		UKismetSystemLibrary::K2_ClearTimerHandle(this, TimerHandle);

		FTimerDynamicDelegate StartDelegate;
		StartDelegate.BindDynamic(this, &UCameraControlComponent::UpdateZoomIn);

		TimerHandle = UKismetSystemLibrary::K2_SetTimerDelegate(StartDelegate, TimeStep, true, true);
		//GetWorld()->GetTimerManager().SetTimer(TimerHandle, StartDelegate, TimeStep, true);
	}
	
}

void UCameraControlComponent::UpdateZoomOut()
{
	UE_LOG(LogTemp, Warning, TEXT("Out"));
	const double TargetLength {ZoomStep * ZoomMultiplier};
	SpringArmComponent->TargetArmLength = UKismetMathLibrary::FInterpTo(SpringArmComponent->TargetArmLength, TargetLength, UGameplayStatics::GetWorldDeltaSeconds(this), InterpSpeed);
	SpringArmComponent->SocketOffset.Z = UKismetMathLibrary::FInterpTo(SpringArmComponent->SocketOffset.Z, TargetSocketOffset, UGameplayStatics::GetWorldDeltaSeconds(this), InterpSpeed);
	if(SpringArmComponent->TargetArmLength >= TargetLength)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	}

}

void UCameraControlComponent::UpdateZoomIn()
{

	SpringArmComponent->TargetArmLength = UKismetMathLibrary::FInterpTo(SpringArmComponent->TargetArmLength, DefaultArmLength, UGameplayStatics::GetWorldDeltaSeconds(this), InterpSpeed);
	SpringArmComponent->SocketOffset.Z = UKismetMathLibrary::FInterpTo(SpringArmComponent->SocketOffset.Z, 0, UGameplayStatics::GetWorldDeltaSeconds(this), InterpSpeed);


	UE_LOG(LogTemp, Warning, TEXT("In = %f"), SpringArmComponent->TargetArmLength);

	if(SpringArmComponent->TargetArmLength <= DefaultArmLength + 1.0)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	}

}