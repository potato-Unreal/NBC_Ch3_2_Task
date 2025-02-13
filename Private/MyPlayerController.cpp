// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "MyGameStateBase.h"
#include "Blueprint/UserWidget.h" 

AMyPlayerController::AMyPlayerController() : HUDWidgetClass(nullptr), HUDWidgetInstance(nullptr)
{

}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (HUDWidgetClass)
	{
		HUDWidgetInstance = CreateWidget<UUserWidget>(this, HUDWidgetClass);
		if (HUDWidgetInstance)
		{
			HUDWidgetInstance->AddToViewport();

			AMyGameStateBase* MyGameState = GetWorld() ? GetWorld()->GetGameState<AMyGameStateBase>() : nullptr;
			if (MyGameState)
			{
				MyGameState->UpdateHUD();
			}
		}
	}
}

UUserWidget* AMyPlayerController::GetHUDWidget() const
{
	return HUDWidgetInstance;
}