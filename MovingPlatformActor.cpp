#include "MovingPlatformActor.h"

AMovingPlatformActor::AMovingPlatformActor()
{
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
}

void AMovingPlatformActor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void AMovingPlatformActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation() + MoveDirection * MoveSpeed * CurrentDirection * DeltaTime;

	if (FVector::Dist(NewLocation, StartLocation) >= MaxRange)
	{
		CurrentDirection *= -1.0f;
	}

	SetActorLocation(NewLocation);
}