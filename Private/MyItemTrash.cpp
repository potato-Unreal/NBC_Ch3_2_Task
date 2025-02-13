// Fill out your copyright notice in the Description page of Project Settings.


#include "MyItemTrash.h"

AMyItemTrash::AMyItemTrash()
{
	ItemName = "Trash";
	ScoreDown = 20;
	UIText = "흔한 쓰레기. 주우면 점수가 낮아질 것 같다.";
}

void AMyItemTrash::ItemActive(AActor* OtherActor)
{
	AMyGameStateBase* MyState = GetWorld()->GetGameState<AMyGameStateBase>();
	MyState->AddLevelScore(-ScoreDown);

	ItemDestroy();
}
