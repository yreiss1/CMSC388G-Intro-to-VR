// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomMotionController.generated.h"


USTRUCT(Blueprintable)
struct FNavMeshNode
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Nav Mesh Result")
		bool bSuccess;
	UPROPERTY(BlueprintReadWrite, Category = "Nav Mesh Result")
		TArray<FVector> TracePoints;
	UPROPERTY(BlueprintReadWrite, Category = "Nav Mesh Result")
		FVector NavMeshLocation;
	UPROPERTY(BlueprintReadWrite, Category = "Nav Mesh Result")
		FVector TraceLocation;
};

UCLASS()
class PROJECT1_API ACustomMotionController : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACustomMotionController();

	UFUNCTION(BlueprintCallable, Category = "Teleporation")
		void ClearArc();

	UFUNCTION(BlueprintCallable, Category = "Grab Handling")
		AActor* GetActorNearHand();

	UFUNCTION(BlueprintCallable, Category = "Teleportation")
		FNavMeshNode TraceTeleportDestination();

};

