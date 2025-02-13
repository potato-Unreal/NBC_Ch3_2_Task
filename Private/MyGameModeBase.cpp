// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyGameStateBase.h"

AMyGameModeBase::AMyGameModeBase()
{
	GameStateClass = AMyGameStateBase::StaticClass();
}
