#include "MyActor.h"
#include "Engine/Engine.h" // UE_LOG를 위한 엔진 헤더 포함

AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = false; // Tick 함수 비활성화
    Start = FVector2D(0.f, 0.f);          // 시작 좌표 초기화
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();
    Move(); // 이동 로직 실행
}

void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    // Tick 함수가 필요 없으므로 비워둡니다.
}

int32 AMyActor::Step()
{
    return FMath::RandRange(0, 1); // 0 또는 1 랜덤 반환
}

void AMyActor::Move()
{
    for (int32 i = 0; i < 10; i++)
    {
        int32 XStep = Step();
        int32 YStep = Step();
        Start.X += XStep;
        Start.Y += YStep;

        UE_LOG(LogTemp, Log, TEXT("Step %d: Current Location: (%.0f, %.0f)"), i + 1, Start.X, Start.Y);
    }
}
