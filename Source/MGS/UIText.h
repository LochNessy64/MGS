// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class MGS_API UIText
{
public:
	UIText(AActor *Actor, FVector2D NewScreenPos, FText TextToDisplay, UFont *NewFont, FLinearColor NewColor);
	~UIText();

	void SetColor(FLinearColor NewColor);

	FLinearColor GetColor();

	void SetOpacity(float NewOpacity);

	float GetOpacity();

	void SetScreenPos(FVector2D NewScreenPos);

	FVector2D GetScreenPos();

	void SetFont(UFont *NewFont);

	UFont* GetFont();

	FTimerHandle* GetFadeTimer();
	
	void SetFadeTimer(float Duration);

	float GetFadeTimerElapsed();

	float GetFadeTimerRemaining();

	float GetFadeTimerDuration();

	void SetFadeTimerDuration(float NewDuration);

	FTimerHandle* GetDisplayTimer();

	void SetDisplayTimer(float Duration);

	float GetDisplayTimerElapsed();

	float GetDisplayTimerRemaining();

	float GetDisplayTimerDuration();

	void SetDisplayTimerDuration(float NewDuration);

	void SetText(FText NewText);
	 
	FText GetText();

	FCanvasTextItem* GetDisplayText();


private:
	FCanvasTextItem *DisplayText;

	FLinearColor Color;

	float Opacity;

	FVector2D ScreenPos;

	UFont *Font;

	FTimerHandle *FadeTimer;

	FTimerHandle *DisplayTimer;

	float FadeTimerDuration;

	float DisplayTimerDuration;

	FTimerManager *TimerManager;

	FText Text;

};
