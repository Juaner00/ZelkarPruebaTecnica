#pragma once

#include "CoreMinimal.h"
#include "MenuBase.h"
#include "GameFramework/HUD.h"
#include "ZelkarHUD.generated.h"

#define GET_HUD() GetWorld()->GetFirstPlayerController()->GetHUD<AZelkarHUD>()


UCLASS(minimalapi)
class AZelkarHUD : public AHUD 
{
	
public:
	GENERATED_BODY()

	UPROPERTY(visibleAnywhere, BlueprintReadOnly)
	TArray<UMenuBase*> MenuStack; 
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta=(DeterminesOutputType="menu"))
	UMenuBase* ShowMenu(TSubclassOf<UMenuBase> Menu);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta=(DeterminesOutputType="menu"))
	UMenuBase* GetMenu(TSubclassOf<UMenuBase> Menu);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, meta=(DeterminesOutputType="menu"))
	void HideMenu(TSubclassOf<UMenuBase> Menu);	
};
