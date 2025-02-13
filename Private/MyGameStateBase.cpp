// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameStateBase.h"
#include "MyGameInstance.h"
#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Blueprint/UserWidget.h"

AMyGameStateBase::AMyGameStateBase()
{
	LevelScore = 0;
	Wave = 0;

	bIsWave = false;
	bIsReady = true;

	WaveTime = 30.0f;
	ReadyTime = 5.0f;
}

void AMyGameStateBase::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(WaveTimerHandle, this, &AMyGameStateBase::TimeOutReady, ReadyTime, false);

	UpdateHUD();

	GetWorldTimerManager().SetTimer(HUDUpdateTimerHandle, this, &AMyGameStateBase::UpdateHUD, 0.1f, true);
}

int AMyGameStateBase::GetLevelScore()
{
	return LevelScore;
}

void AMyGameStateBase::AddLevelScore(int value)
{
	LevelScore += value;

	UpdateHUD();
}

void AMyGameStateBase::TimeOutWave()
{
	GetWorld()->GetTimerManager().ClearTimer(ReadyTimerHandle);
	GetWorld()->GetTimerManager().SetTimer(WaveTimerHandle, this, &AMyGameStateBase::TimeOutReady, ReadyTime, false);

	UpdateHUD();
}

void AMyGameStateBase::TimeOutReady()
{
	GetWorld()->GetTimerManager().ClearTimer(WaveTimerHandle);

	if (Wave < 3)
	{
		GetWorld()->GetTimerManager().SetTimer(ReadyTimerHandle, this, &AMyGameStateBase::TimeOutWave, WaveTime, false);
	}
	else
	{
		EndLevel();
	}

	Wave++;
}

void AMyGameStateBase::EndLevel()
{
	UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GetGameInstance());

	int NowLevelIndex = MyGameInstance->GetNowLevelIndex();
	NowLevelIndex++;

	MyGameInstance->AddNowLevelIndex(NowLevelIndex);
	MyGameInstance->AddTotalScore(LevelScore);

	if (LevelNames.IsValidIndex(NowLevelIndex))
	{
		UGameplayStatics::OpenLevel(GetWorld(), LevelNames[NowLevelIndex]);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString::Printf(TEXT("Level Load Fail : Index %i is not valid."), NowLevelIndex));
	}
}

void AMyGameStateBase::UpdateHUD()
{
	if (UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GetGameInstance()))
	{
		AMyPlayerController* MyController = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());
		{

			if (GetWorldTimerManager().IsTimerActive(ReadyTimerHandle))
			{
				bIsWave = false;
				bIsReady = true;
			}

			if (GetWorldTimerManager().IsTimerActive(WaveTimerHandle))
			{
				bIsWave = true;
				bIsReady = false;
			}


			if (UUserWidget* HUDWidget = MyController->GetHUDWidget())
			{
				// 총 점수
				if (UTextBlock* ScoreText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("GameScore"))))
				{
					if (MyGameInstance)
					{
						ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Total Score   %i"), MyGameInstance->GetTotalScore())));
					}
				}

				// 현재 레벨 점수
				if (UTextBlock* ScoreText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("LevelScore"))))
				{
					if (MyGameInstance)
					{
						ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Now Level Score   %i"), LevelScore)));
					}
				}

				// 현재 레벨 인덱스
				if (UTextBlock* LevelIndexText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Level"))))
				{
					if(MyGameInstance)
					{
						LevelIndexText->SetText(FText::FromString(FString::Printf(TEXT("%i  LEVEL"), MyGameInstance->GetNowLevelIndex() + 1)));
					}
				}

				// 현재 웨이브 텍스트
				if (UTextBlock* LevelIndexText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Wave"))))
				{
					if (MyGameInstance)
					{
						LevelIndexText->SetText(FText::FromString(FString::Printf(TEXT("WAVE - %i"), Wave)));
					}
				}
					
				// 준비 시간 텍스트
				if (UTextBlock* ReadyText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Ready"))))
				{
					if (bIsWave)
					{
						ReadyText->SetVisibility(ESlateVisibility::Visible);
					}
					if (!bIsWave)
					{
						ReadyText->SetVisibility(ESlateVisibility::Hidden);
					}

					if (Wave < 3)
					{
						ReadyText->SetText(FText::FromString(FString::Printf(TEXT("다음 웨이브가 곧 시작됩니다\n준비하세요!"))));
					}
					else
					{
						ReadyText->SetText(FText::FromString(FString::Printf(TEXT("모든 웨이브가 끝났습니다\n다음 레벨을 불러옵니다..."))));
					}
				}

				// 웨이브 시간
				if (UProgressBar* TimeBar = Cast<UProgressBar>(HUDWidget->GetWidgetFromName(TEXT("WaveTime"))))
				{
					if (bIsReady)
					{
						TimeBar->SetVisibility(ESlateVisibility::Visible);
					}
					if (!bIsReady)
					{
						TimeBar->SetVisibility(ESlateVisibility::Hidden);
					}

					float AlphaTime = GetWorldTimerManager().GetTimerRemaining(ReadyTimerHandle) / WaveTime;
					float Percent = FMath::Lerp(0.0f, 1.0f, AlphaTime);
					TimeBar->SetPercent(Percent);
				}

				// 준비 시간
				if (UProgressBar* TimeBar = Cast<UProgressBar>(HUDWidget->GetWidgetFromName(TEXT("ReadyTime"))))
				{
					if(bIsWave)
					{
						TimeBar->SetVisibility(ESlateVisibility::Visible);
					}
					if(!bIsWave)
					{
						TimeBar->SetVisibility(ESlateVisibility::Hidden);
					}

					float AlphaTime = GetWorldTimerManager().GetTimerRemaining(WaveTimerHandle) / ReadyTime;
					float Percent = FMath::Lerp(1.0f, 0.0f, AlphaTime);
					TimeBar->SetPercent(Percent);
				}
			}
		}
	}
}
