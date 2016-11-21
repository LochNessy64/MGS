// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "InventorySlotWidget.h"

void UInventorySlotWidget::SetEquippedItem()
{

}


void UInventorySlotWidget::SetItemTexture(UTexture2D * NewTexture)
{
	NewTexture ? ItemTexture = NewTexture : ItemTexture = nullptr;
}
