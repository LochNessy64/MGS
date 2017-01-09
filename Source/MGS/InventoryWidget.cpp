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
			if (!TempHorizontalWidget && GetWorld()->HasBegunPlay())
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

					if (!TempBPHWidget)
					{
						TempBPHWidget = Cast<UInventoryHorizontalWidget>(WidgetTree->FindWidget(FName("UW_UIInventory_" + i)));
						if (!TempBPHWidget)
							return false;

						UE_LOG(LogTemp, Warning, TEXT("BPHWidget Name: %s"), *TempBPHWidget->GetName());
						TempBPHWidget = TempHorizontalWidget;
					}

				}
				return true;
			}
		}
	}
	return false;
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



