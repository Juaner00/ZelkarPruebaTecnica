#include "MenuBase.h"

#include "ZelkarHUD.h"

void UMenuBase::HideSelf() const
{
	GET_HUD()->HideMenu(GetClass());
}
