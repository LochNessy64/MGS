// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "UIItem.h"
#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class MGS_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	/*Adds the widget into the viewport and populates the inventory slots*/
	UFUNCTION()
		void Show();

	/*Removes the widget from the viewport*/

	UFUNCTION(BlueprintImplementableEvent, Category = UI)
		void Hide();


	/*Stores a reference in order to bind info on inventory slots*/
	
 		TArray<UIItem *> ItemsArray;

		TArray<UWidget *> SlotWidgets;

private:

	
	
};
