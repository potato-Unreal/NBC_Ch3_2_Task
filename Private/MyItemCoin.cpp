// Fill out your copyright notice in the Description page of Project Settings.


#include "MyItemCoin.h"

AMyItemCoin::AMyItemCoin()
{
	ItemName = "Coin";
	ScoreUp = 50;
	UIText = "신비로운 금화";
}

void AMyItemCoin::ItemActive(AActor* OtherActor)
{
	AMyGameStateBase* MyState = GetWorld()->GetGameState<AMyGameStateBase>();
	MyState->AddLevelScore(ScoreUp);

	ItemDestroy();
}
