// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "Blueprint/WidgetTree.h"
#include "Components/TextBlock.h"
#include "InventorySlotWidget.h"
#include "InventoryWidget.h"


void UInventoryWidget::Show()
{
	AddToViewport();

	//this->WidgetTree->GetAllWidgets(SlotWidgets);
	WidgetTree->ForEachWidget([&](UWidget* Widget) { 
		UInventorySlotWidget *SlotWidget = Cast<UInventorySlotWidget>(Widget);
		if (SlotWidget)
		{
			
			UE_LOG(LogTemp, Warning, TEXT("Widget name: %s"), *SlotWidget->GetDisplayLabel());
			//UWidget *ItemInfo = SlotWidget->WidgetTree->FindWidget(FName(TEXT("Item_Info")));
			UTextBlock *ItemInfo = Cast<UTextBlock>(SlotWidget->WidgetTree->FindWidget(FName(TEXT("Item_Info"))));
			UTextBlock *ItemName = Cast<UTextBlock>(SlotWidget->WidgetTree->FindWidget(FName(TEXT("ItemName"))));
			if (ItemInfo)
			{
				//
				UE_LOG(LogTemp, Warning, TEXT("Item info Text: %s"), *(ItemInfo->GetText().ToString()));
				//UE_LOG(LogTemp, Warning, TEXT("Fullname: %s"), *ItemInfo->GetFullName());

				//Set the FONT size, not the text size
			}

			if (ItemName)
			{
				UE_LOG(LogTemp, Warning, TEXT("Item name Text: %s"), *(ItemName->GetText().ToString()));
			}
		}
	});
	for (UIItem * Item : ItemsArray)
	{
		
	}
}

