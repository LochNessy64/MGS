// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "InventorySelectIndicatorWidget.h"


UInventorySelectIndicatorWidget::UInventorySelectIndicatorWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	DefaultColor = FLinearColor(1.0f, 1.0f, 1.0f);

	BackgroundColor = FLinearColor(0.0f, 0.0f, 0.0f);

	CurrSelectedColor = FLinearColor(1.0f, .388f, 0.0f);

	PrevSelectedColor = FLinearColor(.5f, .5f, .5f);

	ColorInUse = DefaultColor;

	IndicatorTexture = CreateDefaultSubobject<UTexture2D>(FName("Indicator Texture"));
}