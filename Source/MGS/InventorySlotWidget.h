// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "UIItem.h"
#include "InventorySlotWidget.generated.h"

/**
 * 
 */
UCLASS()
class MGS_API UInventorySlotWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	/*Holds a reference to the item texture*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UTexture2D *ItemTexture;

	/*Tells the player to equip the represented item from this widget*/
	UFUNCTION(BlueprintCallable, Category = UI)
		void SetEquippedItem();

	UIItem *UIItemRef;

	UFUNCTION()
		void EquippedSetup();

	UFUNCTION()
		void InitialSetup();

	//when slot is currently highlighted by player/when inventory is open
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FLinearColor HighlightSlotColor;

	//when row is in focus but slot is not selected or equipped
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FLinearColor DefaultSlotColor;

	//When row isn't in focus
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FLinearColor PassiveSlotColor;

	//when slot is currently equipped
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FLinearColor EquippedSlotColor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UTextBlock *ItemInfo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool bIsItemInfoVisible;
public:
	UInventorySlotWidget(const FObjectInitializer& ObjectInitializer);

	/*Sets the item texture*/
	UFUNCTION(BlueprintCallable, Category = UI)
		void SetItemTexture(UTexture2D *NewTexture);
	//FORCEINLINE FText GetItemName() { return ItemName; }

	UFUNCTION(BlueprintCallable, Category = "Color")
		FORCEINLINE FLinearColor GetHighlightSlotColor() { return HighlightSlotColor; }

	FORCEINLINE void SetHighlightSlotColor(FLinearColor NewColor) { HighlightSlotColor = NewColor; }

	UFUNCTION(BlueprintCallable, Category = "Color")
		FORCEINLINE FLinearColor GetDefaultSlotColor() { return DefaultSlotColor; }

	FORCEINLINE void SetDefaultSlotColor(FLinearColor NewColor) { DefaultSlotColor = NewColor; }

	UFUNCTION(BlueprintCallable, Category = "Color")
		FORCEINLINE FLinearColor GetPassiveSlotColor() { return PassiveSlotColor; }

	FORCEINLINE void SetPassiveSlotColor(FLinearColor NewColor) { PassiveSlotColor = NewColor; }

	UFUNCTION(BlueprintCallable, Category = "Color")
		FORCEINLINE FLinearColor GetEquippedSlotColor() { return EquippedSlotColor; }

	FORCEINLINE void SetEquippedSlotColor(FLinearColor NewColor) { EquippedSlotColor = NewColor; }

	UFUNCTION(BlueprintCallable, Category = "Item Info")
		FORCEINLINE UTextBlock *GetItemInfo() { return ItemInfo; }

	FORCEINLINE void SetItemInfo(UTextBlock *NewText) { ItemInfo = NewText; }

	UFUNCTION(BlueprintCallable, Category = "Item Info")
		FORCEINLINE bool IsItemInfoVisible() { return bIsItemInfoVisible; }

	FORCEINLINE void SetItemInfoVisibility(bool NewState) { bIsItemInfoVisible = NewState; }
};
