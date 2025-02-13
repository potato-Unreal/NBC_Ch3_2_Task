// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
	TotalScore = 0;
	NowLevelIndex = 0;
}

int UMyGameInstance::GetTotalScore() const
{
	return TotalScore;
}

int UMyGameInstance::GetNowLevelIndex() const
{
	return NowLevelIndex;
}

void UMyGameInstance::AddTotalScore(int value)
{
	TotalScore += value;
}

void UMyGameInstance::AddNowLevelIndex(int value)
{
	NowLevelIndex += value;
}
