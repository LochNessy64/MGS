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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	FRotator TurnRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	FString ItemName;

	FString ItemFullMessage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent *ItemMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
		EItemType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
		bool bIsNameVisible;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
		bool bIsActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
		FString PrereqText;
public:

	AItem();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	void Init(FString ItemName, EItemType TypeOfItem);

	UFUNCTION(BlueprintCallable, Category = "Item Properties")
	EItemType GetItemType();

	UFUNCTION(BlueprintCallable, Category = "Item Properties")
	bool CheckIfNameVisible();

	UFUNCTION(BlueprintCallable, Category = "Item Properties")
		FString ToString();

	FORCEINLINE class UStaticMeshComponent *GetMesh() const { return ItemMesh; }

	bool IsActive();

	void SetActive(bool newActiveState);

	bool WasCollected();

	bool IsInventoryItemFull(class UIItem *InvItem);

	void IdleAnimation(float DeltaSeconds);

	void CantCollectAnimation();

protected:

	UFUNCTION(BlueprintCallable, Category = "Item Properties")
	void SetItemType(EItemType NewType);

	UFUNCTION(BlueprintCallable, Category = "Item Properties")
	void SetNameVisibility(bool NewNameVisibility);

	

};
