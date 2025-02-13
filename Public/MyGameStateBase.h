// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class NBC_CH3_2_TASK_API AMyGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
protected:
	int LevelScore;
	int Wave;

	bool bIsWave;
	bool bIsReady;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level Data");
	TArray<FName> LevelNames;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Data")
	int WaveTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Data")
	int ReadyTime;

	FTimerHandle WaveTimerHandle;
	FTimerHandle ReadyTimerHandle;

	FTimerHandle HUDUpdateTimerHandle;

public:
	AMyGameStateBase();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	int GetLevelScore();

	void AddLevelScore(int value);

	UFUNCTION(BlueprintCallable)
	void TimeOutWave();
	UFUNCTION(BlueprintCallable)
	void TimeOutReady();

	UFUNCTION(BlueprintCallable)
	void EndLevel();

	void UpdateHUD();
};
