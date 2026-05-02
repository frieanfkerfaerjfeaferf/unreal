#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.generated.h"

UCLASS()
class PROJECT6_API ARotatingActor : public AActor
{
	GENERATED_BODY()

public:
	ARotatingActor();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComponent;

	// 회전 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float RotateSpeed;

	// X축 회전
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	bool bRotateX;

	// Y축 회전
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	bool bRotateY;

	// Z축 회전
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	bool bRotateZ;
};