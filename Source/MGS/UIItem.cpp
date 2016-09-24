// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "UIItem.h"

UIItem::UIItem()
{
	bAreBulletsVisible = false;
	bIsSelected = false;
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
