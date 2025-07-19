#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Item.generated.h"


UCLASS(Abstract)
class ZELKARPRUEBATECNICA_API UItem : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	FString Name;

	UPROPERTY(BlueprintReadWrite)
	FString Description;

	UPROPERTY(BlueprintReadWrite)
	int Cost;
};
