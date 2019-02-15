// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomMotionController.h"

// Sets default values
ACustomMotionController::ACustomMotionController()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ACustomMotionController::ClearArc()
{
	//TODO - Clear blue laser arc every frame
}

AActor* ACustomMotionController::GetActorNearHand()
{
	//TODO - Do something other than return null
	return nullptr;
}

FNavMeshNode ACustomMotionController::TraceTeleportDestination()
{
	//TODO - Do something other than return empty struct
	return FNavMeshNode();
}
