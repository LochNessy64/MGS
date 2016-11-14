// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "FailUIText.h"


FailUIText::FailUIText(AActor * Actor, FVector2D NewScreenPos, FText TextToDisplay, UFont * NewFont, FLinearColor NewColor): UIText(Actor, NewScreenPos, TextToDisplay, NewFont, NewColor)
{
	CurrentItem = NewObject<AItem>();
}

FailUIText::~FailUIText()
{
	delete CurrentItem;
}

void FailUIText::SetCurrentItem(AItem * NewItem)
{
	CurrentItem = NewItem;
}

AItem * FailUIText::GetCurrentItem()
{
	return CurrentItem;
}

UITextClassType FailUIText::GetClassType()
{
	return UITextClassType::Fail;
}
