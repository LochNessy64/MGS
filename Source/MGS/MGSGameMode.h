// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "Blueprint/UserWidget.h"
#include "GameFramework/GameMode.h"
#include "MGSGameMode.generated.h"

UCLASS(minimalapi)
class AMGSGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AMGSGameMode();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "UMG Test")
	void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Test")
		TSubclassOf<UUserWidget> StartingWidgetClass;

	UPROPERTY()
		UUserWidget* CurrentWidget;

};



