// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyInterface.h"
#include "MyGameStateBase.h"
#include "Components/WidgetComponent.h"
#include "C:\UnrealProject\NBC_Ch3_2_Task\Source\NBC_Ch3_2_Task\NBC_Ch3_2_TaskCharacter.h"
#include "MyItemBase.generated.h"

class USphereComponent;
class UTextBlock;

UCLASS()
class NBC_CH3_2_TASK_API AMyItemBase : public AActor, public IMyInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyItemBase();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	USceneComponent* Scene;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	USphereComponent* Sphere;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	USphereComponent* SphereUI;*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	FName ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	FString UIText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
	UWidgetComponent* ItemUI;

	UTextBlock* MyText;

public:	
	UFUNCTION()
	virtual void ItemOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	//UFUNCTION()
	//virtual void UIOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	//	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	//UFUNCTION()
	//virtual void UIEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	//	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
	virtual void ItemActive(AActor* OtherActor) override;
	virtual void ItemDestroy() override;

	virtual FName GetItemName() const override;
};
