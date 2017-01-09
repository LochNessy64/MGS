// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "InventoryHorizontalWidget.h"

#define MAX_SLOT_COUNT 4

UInventoryHorizontalWidget::UInventoryHorizontalWidget(const FObjectInitializer & ObjectInitializer)
	:Super(ObjectInitializer)
{
	
}

bool UInventoryHorizontalWidget::Initialize()
{
	Super::Initialize();

	if (IndicatorWidgetBP)
	{
		UE_LOG(LogTemp, Warning, TEXT("IndicatorWidgetBP Set"));
		Indicator = CreateWidget<UInventorySelectIndicatorWidget>(this->GetWorld(), IndicatorWidgetBP);
	}

	if (SlotWidgetBP)
	{
		UE_LOG(LogTemp, Warning, TEXT("SlotWidgetBP Set"));
		for (int i = 0; i < MAX_SLOT_COUNT; i++)
		{
			SlotWidgets.Add(CreateWidget<UInventorySlotWidget>(this->GetWorld(), SlotWidgetBP));
		}
	}
	return false;
}

void UInventoryHorizontalWidget::Show()
{

}

void UInventoryHorizontalWidget::Hide()
{


}