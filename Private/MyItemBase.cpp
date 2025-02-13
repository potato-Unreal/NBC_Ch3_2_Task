// Fill out your copyright notice in the Description page of Project Settings.


#include "MyItemBase.h"
#include "Components/SphereComponent.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"

// Sets default values
AMyItemBase::AMyItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision"));
	Sphere->SetupAttachment(Scene);
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AMyItemBase::ItemOverlap);

	/*SphereUI = CreateDefaultSubobject<USphereComponent>(TEXT("UI Collision"));
	SphereUI->SetupAttachment(Sphere);
	SphereUI->OnComponentBeginOverlap.AddDynamic(this, &AMyItemBase::UIOverlap);
	SphereUI->OnComponentEndOverlap.AddDynamic(this, &AMyItemBase::UIEndOverlap);*/

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	ItemMesh->SetupAttachment(Sphere);

	//ItemUI = CreateDefaultSubobject<UWidgetComponent>(TEXT("Item UI"));
	//ItemUI->SetupAttachment(Sphere);

	//ItemUI->SetWidgetSpace(EWidgetSpace::Screen);

	//ConstructorHelpers::FClassFinder<UUserWidget> MyWBP(TEXT("/Game/UI/WB_Item"));
	//if(MyWBP.Succeeded())
	//{
	//	ItemUI->SetWidgetClass(MyWBP.Class);
	//}

	//UUserWidget* UserWidget = Cast<UUserWidget>(ItemUI->GetWidget());
	//if (UserWidget)
	//{
	//	MyText = Cast<UTextBlock>(UserWidget->GetWidgetFromName(TEXT("ItemText")));

	//	if (MyText)
	//	{
	//		MyText->SetText(FText::FromString(UIText));
	//	}

	//	MyText->SetVisibility(ESlateVisibility::Hidden);
	//}
}

void AMyItemBase::ItemOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Player")) 
	{
		ItemActive(OtherActor);
	}
}

//void AMyItemBase::UIOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	if (OtherActor->ActorHasTag("Player")) 
//	{
//		if (MyText)
//		{
//			MyText->SetVisibility(ESlateVisibility::Visible);
//		}
//	}
//}
//
//void AMyItemBase::UIEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
//{
//	if (OtherActor->ActorHasTag("Player"))
//	{
//		if(MyText)
//		{
//			MyText->SetVisibility(ESlateVisibility::Hidden);
//		}
//	}
//}

void AMyItemBase::ItemActive(AActor* OtherActor)
{
	
}

void AMyItemBase::ItemDestroy()
{
	Destroy();
}

FName AMyItemBase::GetItemName() const
{
	return ItemName;
}

