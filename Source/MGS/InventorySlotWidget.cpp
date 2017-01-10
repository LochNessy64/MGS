// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "InventorySlotWidget.h"

UInventorySlotWidget::UInventorySlotWidget(const FObjectInitializer & ObjectInitializer)
	:Super(ObjectInitializer)
{
	}

bool UInventorySlotWidget::Initialize()
{
	Super::Initialize();
	if (GetWorld())
	{
		HighlightItemColor = FLinearColor(0.046f, 0.026f, 1.0f, 0.295f);

		DefaultSlotColor = FLinearColor(0.0f, 0.0f, 0.0f, 0.5f);

		ItemInfo = FText::FromString("Item Info!");

		ItemName = FText::FromString("Item Name!");

		ItemColorInUse = HighlightItemColor;

		SlotColorInUse = DefaultSlotColor;

		bIsSlotHighlighted = false;

		bIsItemEquipped = false;

		EquippedItemColor = FLinearColor(0.315f, 0.723f, 1.0f);

		bIsItemInfoVisible = false;

		bIsItemNameVisible = true;

		if (UIItemRef)
		{
			ItemTexture = UIItemRef->GetUIItemTexture();
		}

		return true;
	}

	return false;
}

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
		bIsItemInfoVisible = true;
		//Get num of bullets for firearm
		//divide space from bullet space widget by the number of bullets in the clip and the widget of the bullet image
		//show full clip of bullets initially
		//hide item name
		bIsItemNameVisible = false;
		break;
		
	default:
		//show item name and count by default
		bIsItemInfoVisible = true;
		bIsItemNameVisible = true;
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
		bIsItemNameVisible = true;
		bIsItemInfoVisible = false;
		break;

	default:
		//show item name and count by default
		bIsItemInfoVisible = true;
		bIsItemNameVisible = true;
		break;
	}
}


void UInventorySlotWidget::SetItemTexture(UTexture2D * NewTexture)
{
	NewTexture ? ItemTexture = NewTexture : ItemTexture = nullptr;
}
