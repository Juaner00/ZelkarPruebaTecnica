#include "ZelkarHUD.h"

UMenuBase* AZelkarHUD::ShowMenu_Implementation(const TSubclassOf<UMenuBase> Menu)
{
	UMenuBase* ExistingMenu = GetMenu(Menu);

	if (ExistingMenu)
	{
		if (!ExistingMenu->IsInViewport())
			ExistingMenu->AddToViewport();

		return ExistingMenu;
	}

	UMenuBase* NewMenu = Cast<UMenuBase>(CreateWidget(Owner, Menu));

	MenuStack.Add(NewMenu);
	NewMenu->AddToViewport();

	return ExistingMenu;
}

UMenuBase* AZelkarHUD::GetMenu_Implementation(const TSubclassOf<UMenuBase> Menu)
{
	for (UMenuBase* MenuBase : MenuStack)
	{
		if (MenuBase->GetClass() == Menu->GetClass())
			return MenuBase;
	}

	return nullptr;
}

void AZelkarHUD::HideMenu_Implementation(TSubclassOf<UMenuBase> Menu)
{
	UMenuBase* ExistingMenu = GetMenu(Menu);

	if (ExistingMenu)
	{
		ExistingMenu->RemoveFromParent();
	}
}

