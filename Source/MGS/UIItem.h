// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


/**
 * 
 */

enum class EItemType;
enum class EItemLeathality;

class MGS_API UIItem
{

private:
	uint32 MaxCount;
	uint32 CurrentCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Item Properties", meta = (AllowPrivateAccess = "true"))
		EItemType Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Item Properties", meta = (AllowPrivateAccess = "true"))
		EItemLeathality LeathalType;


protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI Item Properties", meta = (AllowPrivateAccess = "true"))
		bool bIsNameVisible;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI Item Properties", meta = (AllowPrivateAccess = "true"))
		bool bAreBulletsVisible;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI Item Properties", meta = (AllowPrivateAccess = "true"))
		bool bIsSelected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Item Properties", Meta = (AllowPrivateAccess = "true"))
		bool bIsVisible;

	UFUNCTION(BlueprintCallable, Category = "UI Item Properties")
		void SetBulletVisibility(bool NewBulletVisibility);

	UFUNCTION(BlueprintCallable, Category = "UI Item Properties")
		void SetItemType(EItemType IType);

	UFUNCTION(BlueprintCallable, Category = "UI Item Properties")
		void SetNameVisibility(bool NewNameVisibility);

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
