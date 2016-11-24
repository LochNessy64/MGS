// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "InventoryWidget.h"
#include "MGSCharacter.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MGS_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	/*Inventory Widget reference*/
	UInventoryWidget *InventoryWidgetRef;

	/*True if the inventory is currently open - false otherwise*/
	bool bIsInventoryOpen;

protected:
	
	/*Inventory widget blueprint reference*/
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UInventoryWidget> InventoryWidgetBP;

public:

	virtual void Possess(APawn *InPawn) override;

	/*Opens or closes the inventory*/
	void HandleInventoryInput();
	
};
