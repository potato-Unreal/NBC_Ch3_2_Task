// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class NBC_CH3_2_TASK_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

protected:
	int TotalScore;
	int NowLevelIndex;

public:
	UMyGameInstance();

	int GetTotalScore() const;
	int GetNowLevelIndex() const;

	void AddTotalScore(int value);
	void AddNowLevelIndex(int value);
};
