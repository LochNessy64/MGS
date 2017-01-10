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
	UPROPERTY(EditDefaultsOnly)
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
		FLinearColor HighlightItemColor;

	//when row is in focus but slot is not selected or equipped
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FLinearColor DefaultSlotColor;

	//When row isn't in focus
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool bIsSlotHighlighted;

	//when slot is currently equipped
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FLinearColor EquippedItemColor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FLinearColor ItemColorInUse;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FLinearColor SlotColorInUse;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FText ItemInfo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool bIsItemInfoVisible;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FText ItemName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool bIsItemNameVisible;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool bIsItemEquipped;

public:
	UInventorySlotWidget(const FObjectInitializer& ObjectInitializer);

	virtual bool Initialize() override;

	/*Sets the item texture*/
	UFUNCTION(BlueprintCallable, Category = UI)
		void SetItemTexture(UTexture2D *NewTexture);
	//FORCEINLINE FText GetItemName() { return ItemName; }

	UFUNCTION(BlueprintCallable, Category = "Color")
		FORCEINLINE FLinearColor GetHighlightItemColor() { return HighlightItemColor; }

	FORCEINLINE void SetHighlightItemColor(FLinearColor NewColor) { HighlightItemColor = NewColor; }

	UFUNCTION(BlueprintCallable, Category = "Color")
		FORCEINLINE FLinearColor GetDefaultSlotColor() { return DefaultSlotColor; }

	FORCEINLINE void SetDefaultSlotColor(FLinearColor NewColor) { DefaultSlotColor = NewColor; }

	UFUNCTION(BlueprintCallable, Category = "Color")
		FORCEINLINE bool IsSlotHighlighted() { return bIsSlotHighlighted; }

	FORCEINLINE void SetSlotHighlight(bool NewState) { bIsSlotHighlighted = NewState; }

	UFUNCTION(BlueprintCallable, Category = "Color")
		FORCEINLINE FLinearColor GetEquippedItemColor() { return EquippedItemColor; }

	FORCEINLINE void SetEquippedItemColor(FLinearColor NewColor) { EquippedItemColor = NewColor; }

	UFUNCTION(BlueprintCallable, Category = "Text")
		FORCEINLINE FText GetItemInfo() { return ItemInfo; }

	FORCEINLINE void SetItemInfo(FText NewText) { ItemInfo = NewText; }

	UFUNCTION(BlueprintCallable, Category = "Text")
		FORCEINLINE bool IsItemInfoVisible() { return bIsItemInfoVisible; }

	FORCEINLINE void SetItemInfoVisibility(bool NewState) { bIsItemInfoVisible = NewState; }

	UFUNCTION(BlueprintCallable, Category = "Text")
		FORCEINLINE FText GetItemName() { return ItemName; }

	FORCEINLINE void SetItemName(FText NewText) { ItemName = NewText; }

	UFUNCTION(BlueprintCallable, Category = "Text")
		FORCEINLINE bool IsItemNameVisible() { return bIsItemNameVisible; }

	FORCEINLINE void SetItemNameVisibility(bool NewState) { bIsItemNameVisible = NewState; }

	UFUNCTION(BlueprintCallable, Category = "Color")
		FORCEINLINE FLinearColor GetItemColorInUse() { return ItemColorInUse; }

	FORCEINLINE void SetItemColorInUse(FLinearColor NewColor) { ItemColorInUse = NewColor; }

	UFUNCTION(BlueprintCallable, Category = "Color")
		FORCEINLINE FLinearColor GetSlotColorInUse() { return SlotColorInUse; }

	FORCEINLINE void SetSlotColorInUse(FLinearColor NewColor) { SlotColorInUse = NewColor; }
};
