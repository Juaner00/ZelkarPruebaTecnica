#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Item.generated.h"


UCLASS(Abstract)
class ZELKARPRUEBATECNICA_API UItem : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
	FString Name;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
	FString Description;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
	UTexture2D* Icon;
	
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
	int Cost;
};
