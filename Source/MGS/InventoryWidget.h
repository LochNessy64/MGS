// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "UIItem.h"
#include "InventorySlotWidget.h"
#include "InventoryHorizontalWidget.h"
#include <iostream>
#include <vector>
#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class MGS_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UInventoryWidget(const FObjectInitializer &ObjectInitializer);

	/*Adds the widget into the viewport and populates the inventory slots*/
	UFUNCTION()
		void Show();

	/*Removes the widget from the viewport*/

	UFUNCTION()
		void Hide();

	virtual bool Initialize() override;
private:

	
protected:

	/*Stores a reference in order to bind info on inventory slots*/

	//TArray<UInventoryHorizontalWidget *> AllHorizontalWidgets;

	std::vector<UInventoryHorizontalWidget *> AllHorizontalWidgets;

	//TArray<UInventoryHorizontalWidget *> VisibleHorizontalWidgets;
	std::vector<UInventoryHorizontalWidget *> VisibleHorizontalWidgets;

	//UInventoryHorizontalWidget *TempHorizontalWidget;

	//UInventoryHorizontalWidget *TempBPHWidget;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UInventoryHorizontalWidget> HorizontalWidgetBP;

	//TArray<UInventoryHorizontalWidget *>::TIterator CurrHorizontalWidget;
	std::vector<UInventoryHorizontalWidget *>::iterator CurrHorizontalWidget;
	//ptr to determine currently equipped item
	std::vector<UInventoryHorizontalWidget *>::iterator CurrentlyEquippedSlotWidget;

	//ptr to determine the previously equipped item
	std::vector<UInventoryHorizontalWidget *>::iterator PrevEquippedSlotWidget;

	//ptr to determine currently SELECTED item when inventory menu is open
	std::vector<UInventoryHorizontalWidget *>::iterator CurrentlySelectedSlotWidget;
};
