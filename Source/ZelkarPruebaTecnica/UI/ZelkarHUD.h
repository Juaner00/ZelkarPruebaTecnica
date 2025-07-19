#pragma once

#include "CoreMinimal.h"
#include "MenuBase.h"
#include "GameFramework/HUD.h"
#include "ZelkarHUD.generated.h"

#define GET_HUD() Cast<AZelkarHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())

UCLASS()
class ZELKARPRUEBATECNICA_API AZelkarHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UMenuBase*> MenuStack; 
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UMenuBase* CurrentMenu; 
	
	UFUNCTION(BlueprintCallable, meta=(DeterminesOutputType="menu"))
	UMenuBase* ShowMenu(TSubclassOf<UMenuBase> Menu);

	UFUNCTION(BlueprintCallable, meta=(DeterminesOutputType="menu"))
	UMenuBase* GetMenu(TSubclassOf<UMenuBase> Menu);

	UFUNCTION(BlueprintCallable, meta=(DeterminesOutputType="menu"))
	void HideMenu(TSubclassOf<UMenuBase> Menu);

	void HideUntilMenu(TSubclassOf<UMenuBase> Menu);
};
