// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "Blueprint/WidgetTree.h"
#include "Components/TextBlock.h"
#include "InventorySlotWidget.h"
#include "InventoryWidget.h"


void UInventoryWidget::Show()
{
	AddToViewport();

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

