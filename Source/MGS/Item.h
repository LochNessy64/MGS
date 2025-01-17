// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WorldObject.h"
#include "Blueprint/UserWidget.h"
#include "UMG.h"
#include "Item.generated.h"

/**
 * The 3D representation of a pickup item
 */
UENUM(BlueprintType)
enum class EItemType : uint8 { Weapon, Firearm, Ammo, Health, Other, None };
UENUM(BlueprintType)
enum class EItemLeathality: uint8 { Leathal, Nonleathal, None };

UCLASS()
class MGS_API AItem : public AWorldObject
{
	GENERATED_BODY()


private:
	
	USoundWave *PickupSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	FRotator TurnRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	FText ItemName;

	FText ItemFullMessage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent *ItemMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
		EItemType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
		bool bIsNameVisible;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
		bool bIsActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
		FText PrereqText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	class USphereComponent* TriggerSphere;

	UPROPERTY()
		bool bWasCollected;
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

	FORCEINLINE class USphereComponent* GetTriggerSphere() const { return TriggerSphere; }

	bool IsActive();

	void SetActive(bool newActiveState);

	bool WasCollected();

	void SetCollected(bool NewCollectState);

	bool DidItemPickupFail();

	FText GetItemName();

	void SetItemName(FText NewName);

	FText GetItemFullText();

	void SetItemFullText(FText NewFullText);

	FText GetPrereqText();

	void SetPrereqText(FText NewPrereqText);

	bool IsInventoryItemFull(class UIItem *InvItem);

	void IdleAnimation(float DeltaSeconds);

	void CantCollectAnimation(float DeltaSeconds);

	/** called when something enters the sphere component*/
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	TScriptDelegate<FWeakObjectPtr> EndDelegate;
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent *OtherComp, int32 OtherBodyIndex);

	void CollectItem();

	void PickUpFailedAnimation();
	void PickUpSuccessAnimation();

	void SetNoCollisionTimer(float Duration);

	FTimerHandle* GetNoCollisionTimer();
	
	float GetNoCollisionTimerElapsed();
	
	float GetNoCollisionTimerRemaining();

	void SetPickupFailTimer(float Duration);

	FTimerHandle* GetPickupFailTimer();

	float GetPickupFailTimerElapsed();

	float GetPickupFailTimerRemaining();

	bool GetIsDisplayTextSet();

	void SetIsDisplayTextSet(bool NewState);

	FVector GetOriginalLocation();
protected:

	UFUNCTION(BlueprintCallable, Category = "Item Properties")
	void SetItemType(EItemType NewType);

	UFUNCTION(BlueprintCallable, Category = "Item Properties")
	void SetNameVisibility(bool NewNameVisibility);

	FTimerHandle *NoCollisionTimer;

	FTimerHandle *PickupFailTimer;

	UPROPERTY()
		bool bDidItemPickupFail;

	UPROPERTY()
		float TriggerSphereRadius;

	UPROPERTY()
		FVector OriginalLocation;

	UPROPERTY()
		TArray<FVector> BoundingVectors;

	void SwitchCollision();

	UPROPERTY()
		bool bIsDisplayTextSet;
};
