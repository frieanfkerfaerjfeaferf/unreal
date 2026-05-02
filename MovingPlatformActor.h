#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatformActor.generated.h"

UCLASS()
class PROJECT6_API AMovingPlatformActor : public AActor
{
	GENERATED_BODY()

public:
	AMovingPlatformActor();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComponent;

	// 이동 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float MoveSpeed = 200.0f;

	// 이동 범위
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float MaxRange = 500.0f;

	// 이동 방향
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	FVector MoveDirection = FVector(1.0f, 0.0f, 0.0f);

protected:
	virtual void BeginPlay() override;

private:
	// 시작 위치
	FVector StartLocation;
	// 현재 방향
	float CurrentDirection = 1.0f;
};