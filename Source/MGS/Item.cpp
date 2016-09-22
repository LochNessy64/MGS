// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "Item.h"

AItem::AItem()
{
	bIsVisible = false;
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item Mesh"));
	RootComponent = ItemMesh;
	Type = EItemType::Other;
	bIsNameVisible = true;
	bAreBulletsVisible = false;
	bIsSelected = false;
}

EItemType AItem::GetItemType()
{
	return EItemType();
}

bool AItem::CheckIfNameVisible()
{
	return false;
}

bool AItem::CheckIfBulletsVisible()
{
	return false;
}

FString AItem::ToString()
{
	return FString();
}

void AItem::SetItemType(EItemType IType)
{
}

void AItem::SetNameVisibility(bool NewNameVisibility)
{
}

void AItem::SetBulletVisibility(bool NewBulletVisibility)
{
}
