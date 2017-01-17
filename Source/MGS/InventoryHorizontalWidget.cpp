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
	if (GetWorld())
	{
		if (IndicatorWidgetBP)
		{
			UE_LOG(LogTemp, Warning, TEXT("IndicatorWidgetBP Set"));

			Indicator = CreateWidget<UInventorySelectIndicatorWidget>(this->GetWorld(), IndicatorWidgetBP);
			if (!Indicator)
				return false;
		}

		if (SlotWidgetBP)
		{
			UE_LOG(LogTemp, Warning, TEXT("SlotWidgetBP Set"));
			for (int i = 0; i < MAX_SLOT_COUNT; i++)
			{
				//UInventorySlotWidget *Slot = CreateWidget<UInventorySlotWidget>(this->GetWorld(), SlotWidgetBP);
				UInventorySlotWidget *Slot = Cast<UInventorySlotWidget>(WidgetTree->FindWidget(FName(*FString("UW_InventorySlot_" + FString::FromInt(i)))));
				if (!Slot)
					return false;
				VisibleSlotWidgets.Add(Slot);
				AllSlotWidgets.Add(Slot);
			}
		}
		return true;
	}
	return false;
}

void UInventoryHorizontalWidget::Show()
{

}

void UInventoryHorizontalWidget::Hide()
{


}

void UInventoryHorizontalWidget::SetAllSlotWidgets(TArray<UInventorySlotWidget*> NewArray)
{
	if (NewArray.Num() == AllSlotWidgets.Num())
	{
		for (int i = 0; i < AllSlotWidgets.Num(); ++i)
		{
			AllSlotWidgets[i]->SetItemTexture( NewArray[i]->GetItemTexture());
			AllSlotWidgets[i]->SetUIItemRef(NewArray[i]->GetUIItemRef());
			AllSlotWidgets[i]->SetItemInfo(NewArray[i]->GetItemInfo());
			AllSlotWidgets[i]->SetItemName(NewArray[i]->GetItemName());
		}

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Arrays aren't the same size"));
	}
}
