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

void AItemTextHUD::PickUpFailedAnimation(AItem * CurrentItem)
{
}

void AItemTextHUD::PickUpSuccessAnimation(AItem * CurrentItem)
{
	FText SuccessText = CurrentItem->GetItemName();
	DisplaySuccessText = new FCanvasTextItem((FVector2D)AHUD::Project(CurrentItem->GetActorLocation()), SuccessText, JLog, CurrentItem->GetSuccessColor());

	DisplaySuccessText->Scale = FVector2D(1.5f, 1.5f);
	Canvas->DrawItem(*DisplaySuccessText);
}

FCanvasTextItem AItemTextHUD::GetDisplaySuccessText()
{
	return *DisplaySuccessText;
}

void AItemTextHUD::SetDisplaySuccessText(FString text, AItem * CurrentItem)
{
	DisplaySuccessText = new FCanvasTextItem((FVector2D)AHUD::Project(CurrentItem->GetActorLocation()), FText::FromString(text), JLog, CurrentItem->GetSuccessColor());
	DisplaySuccessText->Scale.Set(2.0f, 2.0f);
}

FCanvasTextItem AItemTextHUD::GetDisplayFailText()
{
	return *DisplayFailText;
}

void AItemTextHUD::SetDisplayFailText(FString text, AItem * CurrentItem)
{
	DisplayFailText = new FCanvasTextItem((FVector2D)AHUD::Project(CurrentItem->GetActorLocation()), FText::FromString(text), JLog, CurrentItem->GetFailColor());
	DisplayFailText->Scale.Set(2.0f, 2.0f);
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
			PickUpSuccessAnimation(CurrentItem);
			
			if (CurrentItem->GetFadeTextTimerElapsed() == -1.0f && CurrentItem->GetFadeTextTimerRemaining() == -1.0f)
			{
				if (CurrentItem->GetSuccessColor().A >= 0)
				{
					CurrentItem->GetSuccessColor().A -= 0.1f;
				}
			}
		}

	}

	
}

void AItemTextHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}
