// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "UIItem.h"

UIItem::UIItem()
{
	bAreBulletsVisible = false;
	bIsSelected = false;

	//UITexture = CreateDefaultSubobject<UTexture2D>(FName("ItemTexture"));
}

bool UIItem::CheckIfBulletsVisible()
{
	return false;
}

void UIItem::SetBulletVisibility(bool NewBulletVisibility)
{
}

UIItem::~UIItem()
{
}
