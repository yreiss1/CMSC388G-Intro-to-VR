// All new code and art assets are created by Mikhail Sorokin and Galen Stetsyuk from the University of Maryland, College Park.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PulsatingActor.generated.h"

/**
* An actor that uses the statue's static mesh and floats up and down
* like a magic genie in one pst.
*/
UCLASS()
class MYPROJECT_API APulsatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APulsatingActor();

	//Developer Variables
	FVector Location;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Runtime Variables (Set on BeginPlay and after)
	float DeltaIncr;
	float MinZ;

	float Zpos;
	float PulseRange;

	UStaticMeshComponent* MainObject;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



};
