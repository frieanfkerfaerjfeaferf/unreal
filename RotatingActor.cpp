#include "RotatingActor.h"

ARotatingActor::ARotatingActor()
{
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
}

void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();
}

void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float Amount = RotateSpeed * DeltaTime;
	AddActorLocalRotation(FRotator(
		bRotateX ? Amount : 0.0f,
		bRotateZ ? Amount : 0.0f,
		bRotateY ? Amount : 0.0f
	));
}