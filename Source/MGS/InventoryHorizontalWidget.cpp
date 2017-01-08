// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "InventoryHorizontalWidget.h"

#define MAX_SLOT_COUNT 4

UInventoryHorizontalWidget::UInventoryHorizontalWidget(const FObjectInitializer & ObjectInitializer)
	:Super(ObjectInitializer)
{
	if (IndicatorWidgetBP)
	{
		Indicator = CreateWidget<UInventorySelectIndicatorWidget>(this->GetWorld(), IndicatorWidgetBP);
	}

	if (SlotWidgetBP)
	{
		for (int i = 0; i < MAX_SLOT_COUNT; i++)
		{
			SlotWidgets.Add(CreateWidget<UInventorySlotWidget>(this->GetWorld(), SlotWidgetBP));
		}
	}
}

void UInventoryHorizontalWidget::Show()
{

}

void UInventoryHorizontalWidget::Hide()
{


}