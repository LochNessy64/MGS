// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "UIText.h"

/**
 * 
 */


class MGS_API SuccessUIText : public UIText
{
public:
	SuccessUIText(AActor *Actor, FVector2D NewScreenPos, FText TextToDisplay, UFont *NewFont, FLinearColor NewColor);
	~SuccessUIText();

	void SetExternalActorLocation(FVector NewLocation);

	FVector GetExternalActorLocation();

	virtual UITextClassType GetClassType();

private:

	FVector ExternalActorLocation;
};
