// Copyright Epic Games, Inc. All Rights Reserved.

#include "ZelkarGameMode.h"
#include "ZelkarPruebaTecnicaCharacter.h"
#include "UObject/ConstructorHelpers.h"

AZelkarGameMode::AZelkarGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
