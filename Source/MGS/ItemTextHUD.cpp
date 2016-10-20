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
	TimeDurationInSeconds = 3.0f;
}


void AItemTextHUD::SetDisplaySuccessText(AItem *CurrentItem)
{
	FCanvasTextItem * NewDisplaySuccessText = new FCanvasTextItem((FVector2D)AHUD::Project(CurrentItem->GetActorLocation()), CurrentItem->GetItemName(), JLog, CurrentItem->GetSuccessColor());
	NewDisplaySuccessText->Scale.Set(2.0f, 2.0f);
	
	CurrentItem->SetDisplaySuccessText(NewDisplaySuccessText);
	
}


void AItemTextHUD::SetDisplayFailText(AItem * CurrentItem)
{
	FCanvasTextItem * NewDisplayFailText  = new FCanvasTextItem((FVector2D)AHUD::Project(CurrentItem->GetActorLocation()), CurrentItem->GetItemFullText(), JLog, CurrentItem->GetFailColor());
	NewDisplayFailText->Scale.Set(2.0f, 2.0f);

	CurrentItem->SetDisplayFailText(NewDisplayFailText);
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
			
			if (!CurrentItem->IsFadeTextTimerSet())
			{
				CurrentItem->SetFadeTextTimer(true);
				CurrentItem->SetFadeTextTimer(TimeDurationInSeconds);
			}

			SetDisplayFailText(CurrentItem);
			Canvas->DrawItem(*CurrentItem->GetDisplayFailText());

			if (CurrentItem->GetFadeTextTimerElapsed() == -1.0f && CurrentItem->GetFadeTextTimerRemaining() == -1.0f)
			{
				if (CurrentItem->GetFailColor().A >= 0)
				{
					CurrentItem->GetFailColor().A -= 0.1f;
				}
			}
		}

	}

	
}

void AItemTextHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}
