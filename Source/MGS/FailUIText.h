// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "UIText.h"
#include "Item.h"
/**
 * 
 */


class MGS_API FailUIText : public UIText
{
public:
	FailUIText(AActor *Actor, FVector2D NewScreenPos, FText TextToDisplay, UFont *NewFont, FLinearColor NewColor);
	~FailUIText();

	void SetCurrentItem(AItem *NewItem);
	AItem* GetCurrentItem();

	virtual UITextClassType GetClassType();
private:

	AItem *CurrentItem;
};
