// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "Blueprint/WidgetTree.h"
#include "Components/TextBlock.h"
#include "InventorySlotWidget.h"
#include "InventoryWidget.h"

#define MAX_HORIZONTAL_SLOT_COUNT 5

UInventoryWidget::UInventoryWidget(const FObjectInitializer &ObjectInitializer)
	:Super(ObjectInitializer)
{

	if (HorizontalWidgetBP)
	{
		UE_LOG(LogTemp, Warning, TEXT("HorizontalWidgetBP Set"));
		for (int i = 0; i < MAX_HORIZONTAL_SLOT_COUNT; i++)
		{
			UInventoryHorizontalWidget *HWidget = CreateWidget<UInventoryHorizontalWidget>(this->GetWorld(), HorizontalWidgetBP);
			if (i == 0)
			{
				HWidget->GetSlotWidgets()[0]->SetItemName(FText::FromString("NONE"));
			}
			
			HorizontalWidgets.Add(HWidget);
			UInventoryHorizontalWidget *BPHWidget = Cast<UInventoryHorizontalWidget>(WidgetTree->FindWidget(FName("UW_UIInventory_" + i)));
			UE_LOG(LogTemp, Warning, TEXT("BPHWidget Name: %s"), *BPHWidget->GetName());
			BPHWidget = HWidget;

		}
	}
}

void UInventoryWidget::Show()
{
	AddToViewport();

	for (UInventoryHorizontalWidget* HWidget : HorizontalWidgets)
	{

	}
	//for (UIItem * Item : ItemsArray)
	//{
	//	if (Item != nullptr)
	//	{
	//		//how to populqte inventory? rather what to populate it with?
	//		UInventorySlotWidget * swidget = Cast<UInventorySlotWidget>(WidgetTree->FindWidget(FName("UW_InventorySlot1")));
	//		UTextBlock * ItemName = Cast<UTextBlock>(swidget->WidgetTree->FindWidget(FName("ItemName")));
	//		ItemName->SetText(FText::FromString(Item->GetUIItemName()));
	//		Cast<UUniformGridPanel>(swidget->WidgetTree->FindWidget(FName("CurrentClip")))->SetVisibility(ESlateVisibility::Hidden);
	//	}
	//}
}

void UInventoryWidget::Hide()
{
	RemoveFromViewport();
}

