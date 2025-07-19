#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuBase.generated.h"


UCLASS(Blueprintable)
class ZELKARPRUEBATECNICA_API UMenuBase : public UUserWidget
{
	GENERATED_BODY()

	UFUNCTION(Blueprintable)
	void HideSelf() const;
};
