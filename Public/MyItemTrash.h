// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyItemBase.h"
#include "MyItemTrash.generated.h"

/**
 * 
 */
UCLASS()
class NBC_CH3_2_TASK_API AMyItemTrash : public AMyItemBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	int ScoreDown;

public:
	AMyItemTrash();

	virtual void ItemActive(AActor* OtherActor) override;
};
