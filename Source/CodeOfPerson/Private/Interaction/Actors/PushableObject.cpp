// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/Actors/PushableObject.h"

APushableObject::APushableObject()
{
	PrimaryActorTick.bCanEverTick = true;

}

int32 APushableObject::FindClosestPushTransformIndex_Implementation(const FVector2D& InInstigatorLocation, const float InPushRange)
{

	return 0;
}
