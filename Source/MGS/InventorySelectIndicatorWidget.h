// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "InventorySelectIndicatorWidget.generated.h"

/**
 * 
 */
UCLASS()
class MGS_API UInventorySelectIndicatorWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	//Have reference to background color, prev selected color, current selected color, not selected/default color
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UTexture2D *IndicatorTexture;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FLinearColor BackgroundColor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FLinearColor PrevSelectedColor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FLinearColor CurrSelectedColor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FLinearColor DefaultColor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FLinearColor ColorInUse;
public:
	UInventorySelectIndicatorWidget(const FObjectInitializer& ObjectInitializer);
	//Have indicator color change function
	FORCEINLINE void SetColorInUse(FLinearColor NewColor) { ColorInUse = NewColor; }

	//Have indicator get color in use function
	UFUNCTION(BlueprintCallable, Category = "Color")
		FORCEINLINE FLinearColor GetColorInUse() { return ColorInUse; }

	//Have indicator get current selected color function
	UFUNCTION(BlueprintCallable, Category = "Color")
		FORCEINLINE FLinearColor GetCurrSelectedColor() { return CurrSelectedColor; }

	//Have indicator get prev color function
	UFUNCTION(BlueprintCallable, Category = "Color")
		FORCEINLINE FLinearColor GetPrevSelectedColor() { return PrevSelectedColor; }

	//Have indicator get not selected/default color function
	UFUNCTION(BlueprintCallable, Category = "Color")
		FORCEINLINE FLinearColor GetDefaultColor() { return DefaultColor; }
	
};
