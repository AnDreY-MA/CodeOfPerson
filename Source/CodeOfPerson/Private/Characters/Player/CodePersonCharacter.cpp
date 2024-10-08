// Copyright Epic Games, Inc. All Rights Reserved.

#include "Characters/Player/CodePersonCharacter.h"

#include "Animation/CombatAnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CameraControlComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/CombatSystemComponent.h"
#include "Components/CombatWarpingComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "UMG/Widgets/RoundWidget.h"

ACodePersonCharacter::ACodePersonCharacter(const FObjectInitializer& InInitializer) :
	Super(InInitializer), DistanceCkeckJump(50.0), HeigthJump(150.0), MinSpeedJump(300.0) //, CheckJumpDebug(EDrawDebugTrace::None)
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	//GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	CombatWarpingComponent = CreateDefaultSubobject<UCombatWarpingComponent>("CombatWarpingComponent");
	CameraControlComponent = CreateDefaultSubobject<UCameraControlComponent>("CameraControlComponent");

	HealthBarComponent = CreateDefaultSubobject<UWidgetComponent>("HealthBarComponent");
	HealthBarComponent->SetupAttachment(RootComponent);

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	
}

void ACodePersonCharacter::BeginPlay()
{
	Super::BeginPlay();

	auto* AnimInstance{Cast<UCombatAnimInstance>(GetMesh()->GetAnimInstance())};
	
	AnimInstance->InitializeWithAbilitySystem(FindComponentByClass<UCombatSystemComponent>());

	if(auto* Widget{HealthBarComponent->GetWidget()}; Widget)
	{
		UE_LOG(LogTemp, Warning, TEXT("EREWID"));
		HealthBarWidget = Cast<URoundWidget>(Widget);
	}

}

void ACodePersonCharacter::Tick(float DeltaTime)
{
	CheckJumpHeigth();
}

void ACodePersonCharacter::Move(const FInputActionValue& Value)
{
	if (Controller == nullptr) return;
	const FVector2D Movement = Value.Get<FVector2D>();
	const FRotator ControlRotation{ GetControlRotation() };

	double YawOffset{0.0};

	const FVector ForwardDirection{ UKismetMathLibrary::GetForwardVector(FRotator(0.0, ControlRotation.Yaw + YawOffset, 0.0)) };
	const FVector RightDirection{ UKismetMathLibrary::GetRightVector(FRotator(0.0, ControlRotation.Yaw + YawOffset, 0.0)) };
	
	AddMovementInput(ForwardDirection, Movement.Y);
	AddMovementInput(RightDirection, Movement.X);

}

void ACodePersonCharacter::CheckJumpHeigth()
{
	const FVector Start{GetActorLocation() + GetActorForwardVector() * DistanceCkeckJump};
	const FVector End{ Start - FVector(0.0, 0.0, HeigthJump) };

	FHitResult HitResult;
	const TArray<AActor*> IngoreActors{ this };
	const bool bHitResult{ UKismetSystemLibrary::LineTraceSingle(GetWorld(), Start, End, CheckJumpTraceType, true, IngoreActors, EDrawDebugTrace::None, HitResult, true) };
	
	const bool bCanJump{ bHitResult == false && GetCharacterMovement()->IsFalling() == false && UKismetMathLibrary::VSize(GetVelocity()) > MinSpeedJump};
	if (bCanJump)
	{
		Jump();
	}

}