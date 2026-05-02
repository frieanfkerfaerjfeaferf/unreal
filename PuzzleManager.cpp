#include "PuzzleManager.h"

APuzzleManager::APuzzleManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void APuzzleManager::BeginPlay()
{
	Super::BeginPlay();

	// 게임 시작시 전체 스폰
	SpawnAll();

	// 10초마다 SpawnExtra 실행
	GetWorldTimerManager().SetTimer(
		SpawnTimerHandle,
		this,
		&APuzzleManager::SpawnExtra,
		10.0f,
		true
	);
}

void APuzzleManager::SpawnAll()
{
	// 회전 발판 스폰
	for (int32 i = 0; i < NumRotating; i++)
	{
		if (!RotatingClass) continue;

		FVector Location(
			FMath::RandRange(-SpawnRange, SpawnRange),
			FMath::RandRange(-SpawnRange, SpawnRange),
			300.0f
		);

		ARotatingActor* Actor = GetWorld()->SpawnActor<ARotatingActor>(
			RotatingClass, Location, FRotator::ZeroRotator
		);

		if (Actor)
		{
			// 랜덤 회전 속도
			Actor->RotateSpeed = FMath::RandRange(30.0f, 180.0f);
		}
	}

	// 이동 발판 스폰
	for (int32 i = 0; i < NumMoving; i++)
	{
		if (!MovingClass) continue;

		FVector Location(
			FMath::RandRange(-SpawnRange, SpawnRange),
			FMath::RandRange(-SpawnRange, SpawnRange),
			300.0f
		);

		AMovingPlatformActor* Actor = GetWorld()->SpawnActor<AMovingPlatformActor>(
			MovingClass, Location, FRotator::ZeroRotator
		);

		if (Actor)
		{
			// 랜덤 이동 속도와 범위
			Actor->MoveSpeed = FMath::RandRange(100.0f, 400.0f);
			Actor->MaxRange = FMath::RandRange(200.0f, 800.0f);
		}
	}
}

void APuzzleManager::SpawnExtra()
{
	if (!RotatingClass) return;

	FVector Location(
		FMath::RandRange(-SpawnRange, SpawnRange),
		FMath::RandRange(-SpawnRange, SpawnRange),
		300.0f
	);

	GetWorld()->SpawnActor<ARotatingActor>(
		RotatingClass, Location, FRotator::ZeroRotator
	);
}