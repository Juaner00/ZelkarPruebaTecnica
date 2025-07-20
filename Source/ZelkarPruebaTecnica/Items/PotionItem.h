#pragma once

#include "CoreMinimal.h"
#include "BuffType.h"
#include "Engine/DataAsset.h"
#include "Item.h"
#include "PotionItem.generated.h"


UCLASS()
class ZELKARPRUEBATECNICA_API UPotionItem : public UItem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
	TEnumAsByte<EBuffType> BuffType;
};
