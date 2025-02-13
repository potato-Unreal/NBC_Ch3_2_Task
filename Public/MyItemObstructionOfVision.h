// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyItemBase.h"
#include "MyItemObstructionOfVision.generated.h"

/**
 * 
 */
UCLASS()
class NBC_CH3_2_TASK_API AMyItemObstructionOfVision : public AMyItemBase
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	float ObstructTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	float MaxOpacity;

public:
	AMyItemObstructionOfVision();

	virtual void ItemActive(AActor* OtherActor) override;
};
