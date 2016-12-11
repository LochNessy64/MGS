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

bool UIItem::CheckIfNameVisible()
{
	return bIsNameVisible;
}

void UIItem::SetBulletVisibility(bool NewBulletVisibility)
{
}

void UIItem::SetItemType(EItemType IType)
{
	Type = IType;
}

void UIItem::SetNameVisibility(bool NewNameVisibility)
{
	bIsNameVisible = NewNameVisibility;
}

UIItem::~UIItem()
{
}

EItemType UIItem::GetItemType()
{
	return Type;
}
