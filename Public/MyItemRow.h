// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MyItemRow.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FMyItemRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ItemClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItmeName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpawnChance;
};
