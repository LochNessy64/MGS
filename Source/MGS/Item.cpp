// Fill out your copyright notice in the Description page of Project Settings.


#include "MGS.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Item.h"

#define LOCTEXT_NAMESPACE "Mgs Namespace"


AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;
	
	bWasCollected = false;

	bIsFadeTextTimerSet = false;

	SuccessColor = FLinearColor(1.0f, 1.0f, 1.0f);
	FailColor = FLinearColor(1.0f, 0.0f, 0.0f);

	PickupSound = LoadObject<USoundWave>(NULL, TEXT("/Game/Audio/0x0CUnreal.0x0CUnreal"), NULL, LOAD_None, NULL);
	bIsActive = false;
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item Mesh"));
	RootComponent = ItemMesh;

	ItemName = LOCTEXT("Item Name Key", "ITEM NAME");


	ItemMesh->SetCollisionProfileName("OverlapAllDynamic");
	UE_LOG(LogTemp, Warning, TEXT("Current ItemMesh collision preset: %s"), *(ItemMesh->GetCollisionProfileName().ToString()));
	UE_LOG(LogTemp, Warning, TEXT("Current Actor collision enabled: %s"), this->GetActorEnableCollision() ? TEXT("true") : TEXT("false"));
	//this->
	
	//ItemMesh->bGenerateOverlapEvents = true;
	TriggerSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Trigger Sphere"));
	TriggerSphere->InitSphereRadius(105.0f);
	TriggerSphere->SetupAttachment(RootComponent);

	bIsNameVisible = true;
	
	PrereqText = FText::FromString("PRE-REQUISITE TEXT");
	

	ItemFullMessage = FText::FromString(ItemName.ToString() + " FULL");

	TurnRate = FRotator(0.0f, 0.0f, 180.0f);
	TriggerSphere->bGenerateOverlapEvents = true;
	TriggerSphere->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnOverlapBegin);

}

void AItem::BeginPlay()
{
	Super::BeginPlay();

}

void AItem::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	IdleAnimation(DeltaSeconds);
}

void AItem::Init(FString ItemName, EItemType TypeOfItem)
{
	Type = TypeOfItem;
	//this->ItemName = ItemName;  ///Is this really correct?
}

EItemType AItem::GetItemType()
{
	return Type;
}

bool AItem::CheckIfNameVisible()
{
	return bIsNameVisible;
}



//TODO: Fill this out with print out of all vars
FString AItem::ToString()
{
	return FString();
}

void AItem::SetItemType(EItemType NewType)
{
	Type = NewType;

}

void AItem::SetNameVisibility(bool NewNameVisibility)
{
	bIsNameVisible = NewNameVisibility;
}

bool AItem::IsActive() 
{
	return bIsActive;

}

void AItem::SetActive(bool newActiveState)
{
	bIsActive = newActiveState;
}


//TODO: Fill this out to make mesh hidden, and show appropriate text
bool AItem::WasCollected()
{
	return bWasCollected;
}

void AItem::SetCollected(bool NewCollectState)
{
	bWasCollected = NewCollectState;
}

FText AItem::GetItemName()
{
	return ItemName;
}

void AItem::SetItemName(FText NewName)
{
	ItemName = NewName;
}

FText AItem::GetItemFullText()
{
	return ItemFullMessage;
}

void AItem::SetItemFullText(FText NewFullText)
{
	ItemFullMessage = NewFullText;
}

FText AItem::GetPrereqText()
{
	return PrereqText;
}

void AItem::SetPrereqText(FText NewPrereqText)
{
	PrereqText = NewPrereqText;
}

//TODO: Fill this out
//this is called in WasCollected to check if inventory is full or not
bool AItem::IsInventoryItemFull(UIItem *InvItem)
{
	return false;
}

void AItem::IdleAnimation(float DeltaSeconds)
{

	AddActorWorldRotation(TurnRate * DeltaSeconds);

}

void AItem::CantCollectAnimation()
{

}



void AItem::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Beginning Overlap"));
	CollectItem();
	
}

void AItem::CollectItem()
{
	bWasCollected = true;
	this->SetActorEnableCollision(false);
	ItemMesh->bGenerateOverlapEvents = false;
	ItemMesh->SetHiddenInGame(true);

	//SetActorHiddenInGame(true);
	TriggerSphere->bGenerateOverlapEvents = false;
	TriggerSphere->bHiddenInGame = true;
	SetActorTickEnabled(false);
	UGameplayStatics::PlaySound2D(GetWorld(), PickupSound);
	UE_LOG(LogTemp, Warning, TEXT("Current Actor collision enabled: %s"), this->GetActorEnableCollision() ? TEXT("true") : TEXT("false"));
}

FTimerHandle AItem::GetFadeTextTimer()
{
	return FadeTextTimer;
}

void AItem::SetFadeTextTimer(float duration)
{
	GetWorldTimerManager().SetTimer(FadeTextTimer, duration, false);

}

float AItem::GetFadeTextTimerElapsed()
{
	return GetWorldTimerManager().GetTimerElapsed(FadeTextTimer);
}

float AItem::GetFadeTextTimerRemaining()
{
	return GetWorldTimerManager().GetTimerRemaining(FadeTextTimer);
}

bool AItem::IsFadeTextTimerSet()
{
	return bIsFadeTextTimerSet;
}

void AItem::SetFadeTextTimer(bool newTimerState)
{
	bIsFadeTextTimerSet = newTimerState;
}

FLinearColor &AItem::GetSuccessColor()
{
	return SuccessColor;
}


void AItem::SetSuccessColor(float Red, float Green, float Blue, float Alpha)
{
	SuccessColor = FLinearColor(Red, Green, Blue, Alpha);
}

FLinearColor &AItem::GetFailColor()
{
	return FailColor;
}


void AItem::SetFailColor(float Red, float Green, float Blue, float Alpha)
{
	FailColor = FLinearColor(Red, Green, Blue, Alpha);
}

#undef LOCTEXT_NAMESPACE
