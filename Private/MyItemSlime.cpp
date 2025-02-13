// Fill out your copyright notice in the Description page of Project Settings.


#include "MyItemSlime.h"

AMyItemSlime::AMyItemSlime()
{
	ItemName = "Slime";
	SpeedPercent = 50.0f;
	UIText = "귀여운 슬라임이다. 끈적거릴 것 같다.";
}

void AMyItemSlime::ItemActive(AActor* OtherActor)
{
	ANBC_Ch3_2_TaskCharacter* MyCharacter = Cast<ANBC_Ch3_2_TaskCharacter>(OtherActor);
	MyCharacter->MySpeedDown(SpeedPercent);

	ItemDestroy();
}
