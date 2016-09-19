// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MGS.h"
#include "Blueprint/UserWidget.h"
#include "InventoryUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class MGS_API UInventoryUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My User Widget")
		FString MyWidgetName;
	
	
};
