// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomMotionController.h"
#include "Components/SplineMeshComponent.h"
#include "Engine/Engine.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ACustomMotionController::ACustomMotionController()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ACustomMotionController::ClearArc()
{
	FindComponentByClass<SplineMesh
		
	// Clear Arc
	ArcPoints.Empty();
	ArcSpline->ClearSplinePoints();

	for (int32 i = 0; i < ArcSplineMeshes.Num(); i++)
	{
		if (ArcSplineMeshes[i])
		{
			ArcSplineMeshes[i]->DestroyComponent();
		}
	}

	ArcSplineMeshes.Empty();	//TODO - Clear blue laser arc every frame
}

AActor* ACustomMotionController::GetActorNearHand()
{
	
	TArray<AActor*> overlappingActors;

	GrabSphere->GetOverlappingActors( overlappingActors );
	FVector handLocation = GrabSphere->GetComponentLocation();

	AActor* nearest = nullptr;
	float mindist = 99999999999;

	// Find closest overlaping actor
	for ( AActor *actor : overlappingActors )
	{
		bool isPickupable = actor->GetClass()->ImplementsInterface( UPickupable::StaticClass() );
		if ( isPickupable )
		{

			float dist = ( actor->GetActorLocation() - handLocation ).SizeSquared();
			if ( dist < mindist )
			{
				mindist = dist;
				nearest = actor;
			}
		}
	}
	
	//TODO - Do something other than return null
	return nearest;
}

//Blueprint function that is converted to C++ for your convenience.
FTeleportDestinationTransform ACustomMotionController::GetTeleportDestination()
{
	UStaticMeshComponent* TeleportCylinder = FindComponentByClass<UStaticMeshComponent>();
	FVector TeleportLocation = TeleportCylinder->GetComponentLocation();

	FVector DevicePosition;
	FRotator DeviceRotation;
	UHeadMountedDisplayFunctionLibrary::GetOrientationAndPosition(DeviceRotation, DevicePosition);
	const FVector IgnoreHeightDifferenceVector = FVector(DevicePosition.X, DevicePosition.Y, 0);

	FRotator TeleportRotator;
	FVector RotatedVector = TeleportRotator.RotateVector(IgnoreHeightDifferenceVector);

	FVector DiffFromCamera = TeleportLocation - RotatedVector;

	FTeleportDestinationTransform TeleportDestinationTransform;

	TeleportDestinationTransform.DestinationLocation = DiffFromCamera;
	TeleportDestinationTransform.DestinationRotation = TeleportRotator;

	return TeleportDestinationTransform;
}

