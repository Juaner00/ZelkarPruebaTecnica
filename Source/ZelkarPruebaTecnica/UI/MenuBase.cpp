#include "MenuBase.h"

#include ÄZelkarHUD.h

void UMenuBase::HideSelf() const
{
	GET_HUD->HideMenu(GetClass());
}
