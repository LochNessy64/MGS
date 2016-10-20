// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "Item.h"
#include "ItemTextHUD.generated.h"

/**
 * 
 */
UCLASS()
class MGS_API AItemTextHUD : public AHUD
{
	GENERATED_BODY()
	
private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
		UFont *JLog;

	UPROPERTY()
		bool IsTextDisplayed;
	
protected:
	virtual void DrawHUD() override;

	virtual void PostInitializeComponents() override;

	float TimeDurationInSeconds;

public:

	AItemTextHUD(const FObjectInitializer& ObjectInitializer);


	void SetDisplaySuccessText(AItem * CurrentItem);

	void SetDisplayFailText(AItem * CurrentItem);

	bool GetIsTextDisplayed();
	void SetIsTextDisplayed(bool newDisplayState);
};
