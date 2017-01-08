// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "InventorySlotWidget.h"
#include "InventorySelectIndicatorWidget.h"
#include "InventoryHorizontalWidget.generated.h"

/**
 *
 */
UCLASS()
class MGS_API UInventoryHorizontalWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	//Have list of slot widgets
	TArray<UInventorySlotWidget *> SlotWidgets;

	//BP reference
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UInventorySlotWidget> SlotWidgetBP;
	
	//have reference of selected indicator
	UInventorySelectIndicatorWidget * Indicator;

	//BP reference
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UInventorySelectIndicatorWidget> IndicatorWidgetBP;

	UInventorySlotWidget * HighlightedSlot;

public:
	UInventoryHorizontalWidget(const FObjectInitializer &ObjectInitializer);

	//have show and hide function
	void Show();

	void Hide();

	FORCEINLINE UInventorySelectIndicatorWidget *GetIndicator() { return Indicator; }

	FORCEINLINE UInventorySlotWidget *GetHighlightedSlot() { return HighlightedSlot; }

	FORCEINLINE TArray<UInventorySlotWidget *> GetSlotWidgets() { return SlotWidgets; }

};
