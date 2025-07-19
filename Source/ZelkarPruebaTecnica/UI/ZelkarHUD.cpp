#include "ZelkarHUD.h"

UMenuBase* AZelkarHUD::ShowMenu(const TSubclassOf<UMenuBase> Menu)
{
	UMenuBase* ExistingMenu = GetMenu(Menu);

	if (ExistingMenu)
	{
		HideUntilMenu(Menu);
		return ExistingMenu;
	}

	UMenuBase* NewMenu = Cast<UMenuBase>(CreateWidget(GetWorld()->GetFirstPlayerController(), Menu));

	if (CurrentMenu)
		CurrentMenu->RemoveFromParent();
	CurrentMenu = NewMenu;
	CurrentMenu->AddToViewport();
	
	MenuStack.Add(NewMenu);

	return CurrentMenu;
}

UMenuBase* AZelkarHUD::GetMenu(const TSubclassOf<UMenuBase> Menu)
{
	for (UMenuBase* MenuBase : MenuStack)
	{
		if (MenuBase->GetClass() == Menu->GetClass())
			return MenuBase;
	}

	return nullptr;
}

void AZelkarHUD::HideMenu(const TSubclassOf<UMenuBase> Menu)
{
	if (!CurrentMenu)
		return;
	
	if (CurrentMenu->GetClass() == Menu->GetClass())
	{
		CurrentMenu->RemoveFromParent();
		MenuStack.Remove(CurrentMenu);
		
		if (MenuStack.IsEmpty())
			CurrentMenu = nullptr;
		else
			CurrentMenu = MenuStack[MenuStack.Num() - 1];
	}
	else
	{
		MenuStack.Remove(CurrentMenu);
	}
}

void AZelkarHUD::HideUntilMenu(const TSubclassOf<UMenuBase> Menu)
{
	UMenuBase* ExistingMenu = GetMenu(Menu);
 
 	if (!ExistingMenu)
 		return;
 	
 	for (int i = MenuStack.Num() - 1; i >= 0; i--)
 	{
 		if (MenuStack[i]->GetClass() == Menu->GetClass())
 		{
 			MenuStack[i]->AddToViewport();
 			CurrentMenu = MenuStack[i];
 			return;
 		}
 
 		MenuStack[i]->RemoveFromParent();
        MenuStack.RemoveAt(i);
 	}
}
