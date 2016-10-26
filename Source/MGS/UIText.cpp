// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "GameFramework/GameMode.h"
#include "UIText.h"

UIText::UIText(AActor *Actor, FVector2D NewScreenPos, FText TextToDisplay, UFont *NewFont, FLinearColor NewColor)
{    
	TimerManager = &(Actor->GetWorldTimerManager());
	Opacity = 1.0f;

	DisplayText = new FCanvasTextItem(NewScreenPos, TextToDisplay, NewFont, NewColor);
	
	Text = TextToDisplay;
	Color = NewColor;
	ScreenPos = NewScreenPos;
	Font = NewFont;
}

UIText::~UIText()
{
	delete DisplayText;
	DisplayText = nullptr;

}

void UIText::SetColor(FLinearColor NewColor)
{
	Color = NewColor;
}

FLinearColor UIText::GetColor()
{
	return Color;
}

void UIText::SetOpacity(float NewOpacity)
{
	Opacity = NewOpacity;
}

float UIText::GetOpacity()
{
	return Opacity;
}

void UIText::SetScreenPos(FVector2D NewScreenPos)
{
	ScreenPos = NewScreenPos;
}

FVector2D UIText::GetScreenPos()
{
	return ScreenPos;
}

void UIText::SetFont(UFont *NewFont)
{
	Font = NewFont;
}

UFont* UIText::GetFont()
{
	return Font;
}

void UIText::SetText(FText NewText)
{
	Text = NewText;
}

FText UIText::GetText()
{
	return Text;
}

FCanvasTextItem* UIText::GetDisplayText()
{
	return DisplayText;
}

void UIText::SetFadeTimer(float Duration)
{
	
	(*TimerManager).SetTimer(*FadeTimer, Duration, false);
}

FTimerHandle* UIText::GetFadeTimer()
{
	return FadeTimer;
}

float UIText::GetFadeTimerElapsed()
{
	return (*TimerManager).GetTimerElapsed(*FadeTimer);
}

float UIText::GetFadeTimerRemaining()
{
	return (*TimerManager).GetTimerRemaining(*FadeTimer);
}

float UIText::GetFadeTimerDuration()
{
	return FadeTimerDuration;
}

void UIText::SetFadeTimerDuration(float NewDuration)
{
	FadeTimerDuration = NewDuration;
}


void UIText::SetDisplayTimer(float Duration)
{

	(*TimerManager).SetTimer(*DisplayTimer, Duration, false);
}

FTimerHandle* UIText::GetDisplayTimer()
{
	return DisplayTimer;
}

float UIText::GetDisplayTimerElapsed()
{
	return (*TimerManager).GetTimerElapsed(*DisplayTimer);
}

float UIText::GetDisplayTimerRemaining()
{
	return (*TimerManager).GetTimerRemaining(*DisplayTimer);
}

float UIText::GetDisplayTimerDuration()
{
	return DisplayTimerDuration;
}

void UIText::SetDisplayTimerDuration(float NewDuration)
{
	DisplayTimerDuration = NewDuration;
}

