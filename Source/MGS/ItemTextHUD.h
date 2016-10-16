// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "ItemTextHUD.generated.h"

/**
 * 
 */
UCLASS()
class MGS_API AItemTextHUD : public AHUD
{
	GENERATED_BODY()
	
private:
	UPROPERTY()
	FLinearColor SuccessColor;
	UPROPERTY()
	FLinearColor FailColor;

	
	FCanvasTextItem *DisplaySuccessText;
	
	FCanvasTextItem *DisplayFailText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
		UFont *JLog;
	
	void FadeText();

	UPROPERTY()
		bool IsTextDisplayed;
	
protected:
	virtual void DrawHUD() override;

	virtual void PostInitializeComponents() override;

public:

	AItemTextHUD(const FObjectInitializer& ObjectInitializer);

	void PickUpFailedAnimation();
	void PickUpSuccessAnimation();

	FCanvasTextItem GetDisplaySuccessText();
	void SetDisplaySuccessText(FString text, UStaticMeshComponent *ItemMesh);

	FCanvasTextItem GetDisplayFailText();
	void SetDisplayFailText(FString text, UStaticMeshComponent *ItemMesh);

	bool GetIsTextDisplayed();
	void SetIsTextDisplayed(bool newDisplayState);
};
