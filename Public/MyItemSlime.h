// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyItemBase.h"
#include "MyItemSlime.generated.h"

/**
 * 
 */
UCLASS()
class NBC_CH3_2_TASK_API AMyItemSlime : public AMyItemBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	float SpeedPercent;

public:
	AMyItemSlime();

	virtual void ItemActive(AActor* OtherActor) override;
};
