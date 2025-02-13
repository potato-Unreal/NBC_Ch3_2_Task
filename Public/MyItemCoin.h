// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyItemBase.h"
#include "MyItemCoin.generated.h"

/**
 * 
 */
UCLASS()
class NBC_CH3_2_TASK_API AMyItemCoin : public AMyItemBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	int ScoreUp;

public:
	AMyItemCoin();

	virtual void ItemActive(AActor* OtherActor) override;
};
