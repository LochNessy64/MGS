// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "Item.h"
#include "UIText.h"
#include "ItemTextHUD.h"



AItemTextHUD::AItemTextHUD(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{

	IsTextDisplayed = false;
	JLog = LoadObject<UFont>(NULL, TEXT("/Game/Blueprints/J-LOG_Cameron_Edge_Small_Caps.J-LOG_Cameron_Edge_Small_Caps"), NULL, LOAD_None, NULL);
	check(JLog);

}

bool AItemTextHUD::GetIsTextDisplayed()
{
	return IsTextDisplayed;
}

void AItemTextHUD::SetIsTextDisplayed(bool newDisplayState)
{
	IsTextDisplayed = newDisplayState;
}

void AItemTextHUD::DrawHUD()
{
	Super::DrawHUD();
	
	for (TActorIterator<AItem> ItemItr(GetWorld()); ItemItr; ++ItemItr)
	{

		AItem * CurrentItem = *ItemItr;
		//UE_LOG(LogTemp, Warning, TEXT("Time elapsed: %f"), CurrentItem->GetFadeTextTimerElapsed());
		//UE_LOG(LogTemp, Warning, TEXT("Time remaining: %f"), CurrentItem->GetFadeTextTimerRemaining());
		
		if (CurrentItem->WasCollected()) //TODO: add an or condition for if item is full
		{
			UIText SuccessText    

			SetDisplayFailText(CurrentItem);
			Canvas->DrawItem(*CurrentItem->GetDisplayFailText());

			
		}


		//Destroy the actor from the scene
	}

	//TODO: Create a list of UIText that only keeps track of texts that are currently going to or are being drawn

	
}

void AItemTextHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}
