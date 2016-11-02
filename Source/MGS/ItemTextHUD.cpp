// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "Item.h"
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
		if (CurrentItem->GetNoCollisionTimer() == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("No Collision Timer is null"));
		}
		//UE_LOG(LogTemp, Warning, TEXT("Time elapsed: %f"), CurrentItem->GetNoCollisionTimerElapsed());
		//UE_LOG(LogTemp, Warning, TEXT("Time remaining: %f"), CurrentItem->GetNoCollisionTimerRemaining());
		
		if (CurrentItem->WasCollected()) //TODO: add an or condition for if item is full
		{
			//UE_LOG(LogTemp, Warning, TEXT("Is No Collision Timer Active? "), CurrentItem->GetWorldTimerManager().IsTimerActive(*(CurrentItem->GetNoCollisionTimer())) ? TEXT("Yes") : TEXT("No"));
			
			UIText * SuccessText = new UIText(CurrentItem, (FVector2D)AHUD::Project(CurrentItem->GetActorLocation()), CurrentItem->GetItemName(), JLog, FLinearColor(1.0f, 1.0f, 1.0f));
			SuccessText->SetExternalActorLocation(CurrentItem->GetActorLocation());
            //CurrentItem->SetNoCollisionTimer(3.0f);
			//SetDisplayFailText(CurrentItem);
			//Canvas->DrawItem(*CurrentItem->GetDisplayFailText());
			TextArray.Add(SuccessText);

			SuccessText->SetDisplayTimer(3.0f);
			
		
			//Destroy the actor from the scene
			CurrentItem->Destroy();
		}



		 
	}

	//TODO: Create a list of UIText that only keeps track of texts that are currently going to or are being drawn
	for (auto& TextItr : TextArray)
	{
		
		TextItr->GetDisplayText()->Position = (FVector2D)AHUD::Project(TextItr->GetExternalActorLocation());
		Canvas->DrawItem(*(TextItr->GetDisplayText()));

		//check if display timer has finished
		if (TextItr->GetDisplayTimer()->IsValid())
		{
			UE_LOG(LogTemp, Warning, TEXT("Display Time elapsed: %f"), TextItr->GetDisplayTimerElapsed());
			UE_LOG(LogTemp, Warning, TEXT("Display Time remaining: %f"), TextItr->GetDisplayTimerRemaining());
			if (TextItr->GetDisplayTimerElapsed() == -1.0f && TextItr->GetDisplayTimerRemaining() == -1.0f)
			{
				TextItr->SetFadeTimer(0.5f);
				TextItr->GetDisplayTimer()->Invalidate();

				


			}
		}
		if (TextItr->GetFadeTimer()->IsValid())
		{
			UE_LOG(LogTemp, Warning, TEXT("Fade Time elapsed: %f"), TextItr->GetFadeTimerElapsed());
			UE_LOG(LogTemp, Warning, TEXT("Fade Time remaining: %f"), TextItr->GetFadeTimerRemaining());
			if ((TextItr->GetOpacity() >= 0.0f) && !(TextItr->GetFadeTimerElapsed() == -1.0f && TextItr->GetFadeTimerRemaining() == -1.0f))
			{
				TextItr->SetOpacity(TextItr->GetOpacity() - 0.1f);
			}

			if (TextItr->GetFadeTimerElapsed() == -1.0f && TextItr->GetFadeTimerRemaining() == -1.0f)
			{
				//TextArray.RemoveAt(TextArray.)
				//TextItr->~UIText();
			}
		}
	}
	
	

}

void AItemTextHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}
