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
	TArray<UInventorySlotWidget *> AllSlotWidgets;

	TArray<UInventorySlotWidget *> VisibleSlotWidgets;

	//BP reference
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UInventorySlotWidget> SlotWidgetBP;
	
	//have reference of selected indicator
	UInventorySelectIndicatorWidget * Indicator;

	//BP reference
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UInventorySelectIndicatorWidget> IndicatorWidgetBP;

	UInventorySlotWidget * HighlightedSlot;

	bool bIsHorizontalWidgetInFocus;

public:
	UInventoryHorizontalWidget(const FObjectInitializer &ObjectInitializer);

	
	virtual bool Initialize() override;

	//have show and hide function
	void Show();

	void Hide();

	void ShowNone();

	bool CheckIfContainsNone();

	FORCEINLINE UInventorySelectIndicatorWidget *GetIndicator() { return Indicator; }

	FORCEINLINE UInventorySlotWidget *GetHighlightedSlot() { return HighlightedSlot; }

	FORCEINLINE TArray<UInventorySlotWidget *> GetAllSlotWidgets() { return AllSlotWidgets; }

	void SetAllSlotWidgets(TArray<UInventorySlotWidget *> NewArray);

	FORCEINLINE TArray<UInventorySlotWidget *> GetVisibleSlotWidgets() { return VisibleSlotWidgets; }

	FORCEINLINE void SetVisibleSlotWidgets(TArray<UInventorySlotWidget *> NewArray) { VisibleSlotWidgets = NewArray; }

	FORCEINLINE bool IsHorizontalWidgetInFocus() { return bIsHorizontalWidgetInFocus; }

	FORCEINLINE void SetHorizontalWidgetFocus(bool NewState) { bIsHorizontalWidgetInFocus = NewState; }

};
