// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class NBC_CH3_2_TASK_API IMyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void ItemOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) = 0;
	//virtual void UIOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	//	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) = 0;
	//virtual void UIEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	//	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) = 0;
	virtual void ItemActive(AActor* OtherActor) = 0;
	virtual void ItemDestroy() = 0;
	virtual FName GetItemName() const = 0;
};
