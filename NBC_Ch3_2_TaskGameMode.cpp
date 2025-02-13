// Copyright Epic Games, Inc. All Rights Reserved.

#include "NBC_Ch3_2_TaskGameMode.h"
#include "NBC_Ch3_2_TaskCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANBC_Ch3_2_TaskGameMode::ANBC_Ch3_2_TaskGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
