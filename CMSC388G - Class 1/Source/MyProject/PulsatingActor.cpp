// All new code and art assets are created by Mikhail Sorokin and Galen Stetsyuk from the University of Maryland, College Park.

#include "PulsatingActor.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
APulsatingActor::APulsatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create the StaticMesh Component that is attached to this pulsating actor.
	MainObject = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Main Object"));

	//We set the StaticMesh of the StaticMeshComponent, set above, to the statue reference path. 
	UStaticMesh* ObjectRef = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL,
		TEXT("StaticMesh'/Game/StarterContent/Props/SM_Statue.SM_Statue'")));
	MainObject->SetStaticMesh(ObjectRef);

	//The max range that this will "pulse" vertically in cm
	PulseRange = 120.f;
}

// Called when the game starts or when spawned
void APulsatingActor::BeginPlay()
{
	Super::BeginPlay();

	Location = GetActorLocation();
	Zpos = Location.Z;

	MinZ = Zpos + PulseRange;

	//We set this to start at the bottom of the table and rise up to max pulse range.
	DeltaIncr = -PI / 2;
}

// Called every frame
void APulsatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Have to increase this every tick to dynamically update the actor
	DeltaIncr += DeltaTime;

	//ZPos will be MinZ + [-PulseRange, PulseRange]
	Zpos = MinZ + UKismetMathLibrary::Sin(DeltaIncr) * PulseRange;

	//We only want to modify the location of the z coordinate
	Location = FVector(Location.X, Location.Y, Zpos);
	SetActorLocation(Location);


}

