#include "MyActor.h"
#include "Engine/Engine.h" // UE_LOG�� ���� ���� ��� ����

AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = false; // Tick �Լ� ��Ȱ��ȭ
    Start = FVector2D(0.f, 0.f);          // ���� ��ǥ �ʱ�ȭ
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();
    Move(); // �̵� ���� ����
}

void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    // Tick �Լ��� �ʿ� �����Ƿ� ����Ӵϴ�.
}

int32 AMyActor::Step()
{
    return FMath::RandRange(0, 1); // 0 �Ǵ� 1 ���� ��ȯ
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
