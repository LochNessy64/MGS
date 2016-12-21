// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"

#include "MyPlayerController.h"



void AMyPlayerController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

	if (InventoryWidgetBP)
	{
		//Create the inventory widget based on the blueprint reference we will input from within the editor
		InventoryWidgetRef = CreateWidget<UInventoryWidget>(this, InventoryWidgetBP);
	}

	//Initial value
	bIsInventoryOpen = false;

}

void AMyPlayerController::HandleInventoryInput()
{
	AMGSCharacter *Char = Cast<AMGSCharacter>(GetPawn());
	if (InventoryWidgetRef)
	{
		if (bIsInventoryOpen)
		{
			//Mark inventory as closed
			bIsInventoryOpen = false;

			//Remove it from viewport
			InventoryWidgetRef->RemoveFromViewport();
		}
		else
		{
			//Mark the inventory system as open
			bIsInventoryOpen = true;

			//Re-populate the items array
			InventoryWidgetRef->ItemsArray = Char->GetInventory();

			//Show the inventory
			InventoryWidgetRef->Show();
		}
	}
}

