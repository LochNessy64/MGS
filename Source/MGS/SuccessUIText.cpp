// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "SuccessUIText.h"

SuccessUIText::SuccessUIText(AActor *Actor, FVector2D NewScreenPos, FText TextToDisplay, UFont *NewFont, FLinearColor NewColor) : UIText( Actor, NewScreenPos, TextToDisplay, NewFont, NewColor)
{

}

SuccessUIText::~SuccessUIText()
{
}

void SuccessUIText::SetExternalActorLocation(FVector NewLocation)
{
	ExternalActorLocation = NewLocation;
}

FVector SuccessUIText::GetExternalActorLocation()
{
	return ExternalActorLocation;
}

UITextClassType SuccessUIText::GetClassType()
{
	return UITextClassType::Success;
}