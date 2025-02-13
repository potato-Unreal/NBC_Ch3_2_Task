// Fill out your copyright notice in the Description page of Project Settings.


#include "MyItemObstructionOfVision.h"

AMyItemObstructionOfVision::AMyItemObstructionOfVision()
{
	ItemName = "ObstructionOfVision";
	ObstructTime = 2.0f;
	MaxOpacity = 0.8f;
	UIText = "귀여운 풍선이다. 터쳐볼까?";
}

void AMyItemObstructionOfVision::ItemActive(AActor* OtherActor)
{
	ANBC_Ch3_2_TaskCharacter* MyCharacter = Cast<ANBC_Ch3_2_TaskCharacter>(OtherActor);
	MyCharacter->Obstruction(ObstructTime, MaxOpacity);

	ItemDestroy();
}
