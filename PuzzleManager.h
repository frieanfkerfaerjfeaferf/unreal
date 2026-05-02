#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.h"
#include "MovingPlatformActor.h"
#include "PuzzleManager.generated.h"

UCLASS()
class PROJECT6_API APuzzleManager : public AActor
{
	GENERATED_BODY()

public:
	APuzzleManager();

protected:
	virtual void BeginPlay() override;

public:
	// 회전 발판 스폰 개수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	int32 NumRotating = 3;

	// 이동 발판 스폰 개수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	int32 NumMoving = 3;

	// 스폰 범위
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float SpawnRange = 1000.0f;

	// 회전 발판 클래스
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	TSubclassOf<ARotatingActor> RotatingClass;

	// 이동 발판 클래스
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	TSubclassOf<AMovingPlatformActor> MovingClass;

private:
	// 타이머 핸들
	FTimerHandle SpawnTimerHandle;

	// 시작시 전체 스폰
	void SpawnAll();

	// 타이머로 추가 스폰
	void SpawnExtra();
};