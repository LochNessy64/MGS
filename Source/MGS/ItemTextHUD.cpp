// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "Item.h"
#include "ItemTextHUD.h"



AItemTextHUD::AItemTextHUD(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	SuccessColor = FLinearColor(1.0f, 1.0f, 1.0f);
	FailColor = FLinearColor(1.0f, 0.0f, 0.0f);

	TimerState = 0;

	IsTextDisplayed = false;
	JLog = LoadObject<UFont>(NULL, TEXT("/Game/Blueprints/J-LOG_Cameron_Edge_Small_Caps.J-LOG_Cameron_Edge_Small_Caps"), NULL, LOAD_None, NULL);
	check(JLog);
}

void AItemTextHUD::PickUpFailedAnimation(AItem * CurrentItem)
{
}

void AItemTextHUD::PickUpSuccessAnimation(AItem * CurrentItem)
{
	FText SuccessText = CurrentItem->GetItemName();
	DisplaySuccessText = new FCanvasTextItem((FVector2D)AHUD::Project(CurrentItem->GetActorLocation()), SuccessText, JLog, SuccessColor);

	DisplaySuccessText->Scale = FVector2D(1.5f, 1.5f);
	Canvas->DrawItem(*DisplaySuccessText);
}

FCanvasTextItem AItemTextHUD::GetDisplaySuccessText()
{
	return *DisplaySuccessText;
}

void AItemTextHUD::SetDisplaySuccessText(FString text, UStaticMeshComponent* ItemMesh)
{
	DisplaySuccessText = new FCanvasTextItem(FVector2D(ItemMesh->K2_GetComponentLocation().X, ItemMesh->K2_GetComponentLocation().Y), FText::FromString(text), JLog, SuccessColor);
	DisplaySuccessText->Scale.Set(2.0f, 2.0f);
}

FCanvasTextItem AItemTextHUD::GetDisplayFailText()
{
	return *DisplayFailText;
}

void AItemTextHUD::SetDisplayFailText(FString text, UStaticMeshComponent* ItemMesh)
{
	DisplayFailText = new FCanvasTextItem(FVector2D(ItemMesh->GetComponentLocation().X, ItemMesh->GetComponentLocation().Y), FText::FromString(text), JLog, FailColor);
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
		if (CurrentItem->WasCollected()) //TODO: add an or condition for if item is full
		{
			if (CurrentItem->GetWorldTimerManager().GetTimerElapsed(FadeTextTimer) == -1.0f && CurrentItem->GetWorldTimerManager().GetTimerRemaining(FadeTextTimer) == -1.0f)
			{
				if (SuccessColor.A >= 0)
				{
					SuccessColor.A -= 0.1f;
				}
			}
			if (TimerState == 0)
			{
				TimerState = 1;
				CurrentItem->GetWorldTimerManager().SetTimer(FadeTextTimer, 3.0f, false);
			}
			PickUpSuccessAnimation(CurrentItem);
			UE_LOG(LogTemp, Warning, TEXT("Time elapsed: %f"), CurrentItem->GetWorldTimerManager().GetTimerElapsed(FadeTextTimer));
			UE_LOG(LogTemp, Warning, TEXT("Time remaining: %f"), CurrentItem->GetWorldTimerManager().GetTimerRemaining(FadeTextTimer));
			
		}

	}

	
}

void AItemTextHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}
