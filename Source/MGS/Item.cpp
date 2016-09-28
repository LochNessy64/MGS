// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "Item.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;
	bIsActive = false;
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item Mesh"));
	RootComponent = ItemMesh;
	ItemMesh->bGenerateOverlapEvents = true;
	TriggerSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Trigger Sphere"));
	TriggerSphere->InitSphereRadius(105.0f);
	TriggerSphere->SetupAttachment(RootComponent);

	bIsNameVisible = true;
	
	PrereqText = "PRE-REQUISITE TEXT";
	ItemName = "ITEM NAME";

	ItemFullMessage = ItemName + " FULL";

	TurnRate = FRotator(0.0f, 0.0f, 180.0f);
	TriggerSphere->bGenerateOverlapEvents = true;
	TriggerSphere->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnOverlapBegin);
	
	//UE_LOG(LogTemp, Warning, TEXT("Can Ever Tick? : %s"), PrimaryActorTick.bCanEverTick ? TEXT("True") : TEXT("False"));
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
	this->ItemName = ItemName;  ///Is this really correct?
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
	return false;
}

//TODO: Fill this out
//this is called in WasCollected to check if inventory is full or not
bool AItem::IsInventoryItemFull(UIItem *InvItem)
{
	return false;
}

void AItem::IdleAnimation(float DeltaSeconds)
{
	//UE_LOG(LogTemp, Warning, TEXT("In Idle Animation"));
	
	//AddActorLocalRotation(TurnRate * DeltaSeconds);
	AddActorWorldRotation(TurnRate * DeltaSeconds);
	//float rotation = TurnRate.Yaw * DeltaSeconds;
	//UE_LOG(LogTemp, Warning, TEXT("Rotation %f "), rotation);
}

void AItem::CantCollectAnimation()
{

}

void AItem::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Beginning Overlap"));
	SetActorHiddenInGame(true);
	TriggerSphere->bGenerateOverlapEvents = false;
	TriggerSphere->bHiddenInGame = true;
	SetActorTickEnabled(false);
}
