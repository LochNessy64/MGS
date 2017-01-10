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
	UPROPERTY(EditDefaultsOnly)
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

	virtual bool Initialize() override;
	
	UFUNCTION(BlueprintCallable, Category = "Color")
		FORCEINLINE FLinearColor GetBackgroundColor() { return BackgroundColor; }

	FORCEINLINE void SetBackgroundColor(FLinearColor NewColor) { BackgroundColor = NewColor; }

	//Have indicator get color in use function
	UFUNCTION(BlueprintCallable, Category = "Color")
		FORCEINLINE FLinearColor GetColorInUse() { return ColorInUse; }

	//Have indicator color change function
	FORCEINLINE void SetColorInUse(FLinearColor NewColor) { ColorInUse = NewColor; }

	//Have indicator get current selected color function
	UFUNCTION(BlueprintCallable, Category = "Color")
		FORCEINLINE FLinearColor GetCurrSelectedColor() { return CurrSelectedColor; }

	FORCEINLINE void SetCurrSelectedColor(FLinearColor NewColor) { CurrSelectedColor = NewColor; }

	//Have indicator get prev color function
	UFUNCTION(BlueprintCallable, Category = "Color")
		FORCEINLINE FLinearColor GetPrevSelectedColor() { return PrevSelectedColor; }

	FORCEINLINE void SetPrevSelectedColor(FLinearColor NewColor) { PrevSelectedColor = NewColor; }

	//Have indicator get not selected/default color function
	UFUNCTION(BlueprintCallable, Category = "Color")
		FORCEINLINE FLinearColor GetDefaultColor() { return DefaultColor; }

	FORCEINLINE void SetDefaultColor(FLinearColor NewColor) { DefaultColor = NewColor; }
	
};
