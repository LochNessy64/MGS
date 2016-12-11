// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "InventorySlotWidget.h"

//send event to change animation so character has item in hand
void UInventorySlotWidget::SetEquippedItem()
{
	//
}

//TODO: fill in logic to make children widgets in/visible depending on case
/**Changes what item information is displayed while equipped*/
void UInventorySlotWidget::EquippedSetup()
{
	switch (UIItemRef->GetItemType())
	{
	case EItemType::Firearm:
		//Get num of bullets for firearm
		//divide space from bullet space widget by the number of bullets in the clip and the widget of the bullet image
		//show full clip of bullets initially
		//hide item name
		break;
		
	default:
		//show item name and count by default
		break;
	}
}

//TODO: Fill in logic to make children widgets in/visible depending on case
/**shows item information while looking through the inventory*/
void UInventorySlotWidget::InitialSetup()
{
	switch (UIItemRef->GetItemType())
	{
	case EItemType::Other:
	case EItemType::None:
		//show only item name since these types of items won't have a count.
		break;

	default:
		//show item name and count by default
		break;
	}
}


void UInventorySlotWidget::SetItemTexture(UTexture2D * NewTexture)
{
	NewTexture ? ItemTexture = NewTexture : ItemTexture = nullptr;
}
