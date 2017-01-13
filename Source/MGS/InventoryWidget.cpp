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
	//TODO: Move this to initialize function you're going to override and call the superclass
	
}

bool UInventoryWidget::Initialize()
{
	Super::Initialize();

	if (HorizontalWidgetBP)
	{
		UE_LOG(LogTemp, Warning, TEXT("HorizontalWidgetBP Set"));
		if (GetWorld())
		{
			if (!TempHorizontalWidget )
			{
				for (int i = 0; i < MAX_HORIZONTAL_SLOT_COUNT; i++)
				{
					TempHorizontalWidget = CreateWidget<UInventoryHorizontalWidget>(this->GetWorld(), HorizontalWidgetBP);
					if (!TempHorizontalWidget)
						return false;

					if (i == 0)
					{
						TempHorizontalWidget->GetSlotWidgets()[0]->SetItemName(FText::FromString("NONE"));
					}

					HorizontalWidgets.Add(TempHorizontalWidget);

					TempBPHWidget = Cast<UInventoryHorizontalWidget>(WidgetTree->FindWidget(FName(*FString("UW_UIInventory_" + FString::FromInt(i)))));
					
					if (!TempBPHWidget)
						return false;

					UE_LOG(LogTemp, Warning, TEXT("BPHWidget Name: %s"), *TempBPHWidget->GetName());

					//I don't think this statement is actually making the widgets from the BP change

					UE_LOG(LogTemp, Warning, TEXT("BPHWidget Slot Item Name: %s"), *TempBPHWidget->GetSlotWidgets()[0]->GetItemName().ToString());
					TempBPHWidget->GetSlotWidgets()[0]->SetItemInfo(FText::FromString("AAAAAAAAAAAAAAAAAAAAAAAHHHHHHHHH"));
					UE_LOG(LogTemp, Warning, TEXT("BPHWidget Slot Item Name: %s"), *TempBPHWidget->GetSlotWidgets()[0]->GetItemName().ToString());

				}
				return true;
			}
		}
	}
	return false;
}

void UInventoryWidget::Show()
{
	UE_LOG(LogTemp, Warning, TEXT("In UInventoryWidget::Show()"));
	AddToViewport();

	for (UInventoryHorizontalWidget* HWidget : HorizontalWidgets)
	{
		UE_LOG(LogTemp, Warning, TEXT("HWidget Slot Item Name"))
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
	UE_LOG(LogTemp, Warning, TEXT("In UInventoryWidget::Hide()"));
}



