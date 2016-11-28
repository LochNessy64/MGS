// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "Blueprint/WidgetTree.h"
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
			Widget = Cast<UInventorySlotWidget>(Widget);
			UE_LOG(LogTemp, Warning, TEXT("Widget name: %s"), *Widget->GetDisplayLabel());
			SlotWidget->WidgetTree->ForEachWidget([&](UWidget* ChildWidget) {UE_LOG(LogTemp, Warning, TEXT("Child Widget name: %s"), *ChildWidget->GetDisplayLabel()); });
		}
	});
	for (UIItem * Item : ItemsArray)
	{
		
	}
}

