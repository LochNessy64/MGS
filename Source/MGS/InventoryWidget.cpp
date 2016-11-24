// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "Blueprint/WidgetTree.h"
#include "InventoryWidget.h"


void UInventoryWidget::Show()
{
	AddToViewport();

	//this->WidgetTree->GetAllWidgets(SlotWidgets);
	WidgetTree->ForEachWidget([&](UWidget* Widget) { UE_LOG(LogTemp, Warning, TEXT("Widget name: %s"), *Widget->GetDisplayLabel()); });
	for (UIItem * Item : ItemsArray)
	{
		
	}
}

