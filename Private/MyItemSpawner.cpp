// Fill out your copyright notice in the Description page of Project Settings.


#include "MyItemSpawner.h"
#include "Components/BoxComponent.h"

// Sets default values
AMyItemSpawner::AMyItemSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	SetRootComponent(Scene);

	SpawnVollume = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	SpawnVollume->SetupAttachment(Scene);

	NumOfItems = 5;
	NumOfMustItem = 5;
}

// Called when the game starts or when spawned
void AMyItemSpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnItemMust();
	SpawnItemChance();
}

FVector AMyItemSpawner::RandomLocation()
{
	FVector BoxOrigin = SpawnVollume->GetComponentLocation();
	FVector BoxExtent = SpawnVollume->GetScaledBoxExtent();

	FVector RandomLocation = BoxOrigin + FVector(
		FMath::FRandRange(-BoxExtent.X, BoxExtent.X),
		FMath::FRandRange(-BoxExtent.Y, BoxExtent.Y),
		FMath::FRandRange(-BoxExtent.Z, BoxExtent.Z));

	return RandomLocation;
}

TArray<FMyItemRow*> AMyItemSpawner::GetItemRowIsMust()
{
	if (!ItemDataTable) return TArray<FMyItemRow*>();

	TArray<FMyItemRow*> Rows;
	TArray<FMyItemRow*> MustRows;
	const FString ContextString(TEXT("ItemSpawnerContext"));
	ItemDataTable->GetAllRows(ContextString, Rows);

	for (FMyItemRow* temp : Rows)
	{
		if (temp->SpawnChance == 0.0f)
		{
			MustRows.Add(temp);
		}
	}

	return MustRows;
}

FMyItemRow* AMyItemSpawner::GetItemRowRandomChance()
{
	if (!ItemDataTable) return nullptr;

	TArray<FMyItemRow*> Rows;
	const FString ContextString(TEXT("ItemSpawnerContext"));
	ItemDataTable->GetAllRows(ContextString, Rows);

	// ÀüÃ¼ È®·ü °è»ê
	float TotalChance = 0.0f;
	for (FMyItemRow* temp : Rows)
	{
		TotalChance += temp->SpawnChance;
	}

	// ·£´ý È®·ü Àû¿ë
	float RandomChance = FMath::FRandRange(0.0f, TotalChance);
	float ChanceTemp = 0.0f;
	for (FMyItemRow* temp : Rows)
	{
		ChanceTemp += temp->SpawnChance;

		if (ChanceTemp >= RandomChance)
		{
			return temp;
		}
	}
	
	return nullptr;
}

void AMyItemSpawner::SpawnItem(TSubclassOf<AActor> ItemClass)
{
	GetWorld()->SpawnActor<AActor>(ItemClass, RandomLocation(), FRotator(0.0f, FMath::FRandRange(0.0f, 360.0f), 0.0f));
}

void AMyItemSpawner::SpawnItemMust()
{
	for (FMyItemRow* ItemRow : GetItemRowIsMust())
	{
		if (FMyItemRow* SelectedItem = ItemRow)
		{
			if (UClass* ItemClass = SelectedItem->ItemClass.Get())
			{
				for (int i = 0; i < NumOfMustItem; i++)
				{
					SpawnItem(ItemClass);
				}
			}
		}
	}
}

void AMyItemSpawner::SpawnItemChance()
{
	for (int i = 0; i < NumOfItems; i++)
	{
		if (FMyItemRow* SelectedItem = GetItemRowRandomChance())
		{
			if (UClass* ItemClass = SelectedItem->ItemClass.Get())
			{
				SpawnItem(ItemClass);
			}
		}
	}
}
