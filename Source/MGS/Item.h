// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WorldObject.h"

#include "Item.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EItemType : uint8 { Weapon, Ammo, Health, Other };
UENUM(BlueprintType)
enum class EItemLeathality: uint8 { Leathal, Nonleathal, None };

UCLASS()
class MGS_API AItem : public AWorldObject
{
	GENERATED_BODY()


private:
	
	uint32 MaxCount;
	uint32 CurrentCount;
	FString ItemName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent *ItemMesh;

public:

	AItem();

	UFUNCTION(BlueprintCallable, Category = "Item Properties")
	EItemType GetItemType();

	UFUNCTION(BlueprintCallable, Category = "Item Properties")
	bool CheckIfNameVisible();

	UFUNCTION(BlueprintCallable, Category = "Item Properties")
	bool CheckIfBulletsVisible();

	UFUNCTION(BlueprintCallable, Category = "Item Properties")
		FString ToString();

	FORCEINLINE class UStaticMeshComponent *GetMesh() const { return ItemMesh; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	EItemType Type;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	bool bIsNameVisible;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	bool bAreBulletsVisible;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	bool bIsSelected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", Meta = (AllowPrivateAccess = "true"))
	bool bIsVisible;

	UFUNCTION(BlueprintCallable, Category = "Item Properties")
	void SetItemType(EItemType IType);

	UFUNCTION(BlueprintCallable, Category = "Item Properties")
	void SetNameVisibility(bool NewNameVisibility);

	UFUNCTION(BlueprintCallable, Category = "Item Properties")
		void SetBulletVisibility(bool NewBulletVisibility);
	

};
