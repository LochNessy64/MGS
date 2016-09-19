// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WorldObject.h"

#include "Item.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ItemType : uint8 { Weapon, Ammo, Health, Other };
UENUM(BlueprintType)
enum class ItemLeathality: uint8 { Leathal, Nonleathal, None };

UCLASS()
class MGS_API AItem : public AWorldObject
{
	GENERATED_BODY()


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	ItemType Type;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	bool IsVisible;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	bool IsNameVisible;
	bool AreBulletsVisible;
	bool IsSelected;
	uint32 MaxCount;
	uint32 CurrentCount;
	FString ItemName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent * ItemMesh;
public:
	AItem();

	UFUNCTION(BlueprintCallable, Category = "Item Properties")
	ItemType GetItemType();
	bool CheckIfNameVisible();

protected:
	UFUNCTION(BlueprintCallable, Category = "Item Properties")
	void SetItemType(ItemType IType);
	
	
};
