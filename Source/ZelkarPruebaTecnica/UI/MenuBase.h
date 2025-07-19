#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuBase.generated.h"

UCLASS(Blueprintable)
class UMenuBase : public UUserWidget
{
public:
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	void HideSelf() const;

};
