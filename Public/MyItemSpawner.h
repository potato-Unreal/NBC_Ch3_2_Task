// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyItemRow.h"
#include "MyItemSpawner.generated.h"

class UBoxComponent;

UCLASS()
class NBC_CH3_2_TASK_API AMyItemSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyItemSpawner();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Componenets")
	USceneComponent* Scene;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Componenets")
	UBoxComponent* SpawnVollume;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
	UDataTable* ItemDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
	int NumOfItems;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
	int NumOfMustItem;

	virtual void BeginPlay() override;

public:	
	FVector RandomLocation();

	TArray< FMyItemRow*> GetItemRowIsMust();
	FMyItemRow* GetItemRowRandomChance();

	void SpawnItem(TSubclassOf<AActor> ItemClass);

	void SpawnItemMust();
	void SpawnItemChance();
};
