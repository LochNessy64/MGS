// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



/**
 * The HUD representation of a collection of pickup items
 */

enum class EItemType: uint8;
enum class EItemLeathality : uint8;

class MGS_API UIItem
{

private:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Item Properties", meta = (AllowPrivateAccess = "true"))
		EItemType Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Item Properties", meta = (AllowPrivateAccess = "true"))
		EItemLeathality LeathalType;


protected:

	UPROPERTY()
	uint32 MaxCount;
	UPROPERTY()
	uint32 CurrentCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI Item Properties", meta = (AllowPrivateAccess = "true"))
		bool bIsNameVisible;

	UPROPERTY(EditAnywhere, Category = "UI Item Properties")
		UTexture2D *UIItemTexture;
	//To be moved to a derived class for firearms
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI Item Properties", meta = (AllowPrivateAccess = "true"))
		bool bAreBulletsVisible;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI Item Properties", meta = (AllowPrivateAccess = "true"))
		bool bIsSelected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Item Properties", Meta = (AllowPrivateAccess = "true"))
		bool bIsVisible;
	//To be moved to a derived class for firearms
	UFUNCTION(BlueprintCallable, Category = "UI Item Properties")
		void SetBulletVisibility(bool NewBulletVisibility);

	UFUNCTION(BlueprintCallable, Category = "UI Item Properties")
		void SetItemType(EItemType IType);

	UFUNCTION(BlueprintCallable, Category = "UI Item Properties")
		void SetNameVisibility(bool NewNameVisibility);

	UPROPERTY(EditAnywhere, Category = "UI Item Properties")
		FString UIItemName;
public:
	UIItem();
	~UIItem();

	UFUNCTION(BlueprintCallable, Category = "UI Item Properties")
		EItemType GetItemType();

	UFUNCTION(BlueprintCallable, Category = "UI Item Properties")
		bool CheckIfBulletsVisible();

	UFUNCTION(BlueprintCallable, Category = "UI Item Properties")
		bool CheckIfNameVisible();
};
