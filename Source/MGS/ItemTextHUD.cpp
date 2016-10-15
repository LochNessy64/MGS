// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "ItemTextHUD.h"



AItemTextHUD::AItemTextHUD(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	SuccessColor = FLinearColor(1.0f, 1.0f, 1.0f);
	FailColor = FLinearColor(1.0f, 0.0f, 0.0f);

	IsTextDisplayed = false;
	check(JLog);
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
	DisplayFailText = new FCanvasTextItem(FVector2D(ItemMesh->K2_GetComponentLocation().X, ItemMesh->K2_GetComponentLocation().Y), FText::FromString(text), JLog, FailColor);
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
	if (IsTextDisplayed) {
		Canvas->DrawItem(*DisplaySuccessText);
	}

	Super::DrawHUD();
}