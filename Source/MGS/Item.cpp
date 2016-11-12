// Fill out your copyright notice in the Description page of Project Settings.


#include "MGS.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Item.h"

#define LOCTEXT_NAMESPACE "Mgs Namespace"


AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;
	
	NoCollisionTimer = new FTimerHandle();
	
	PickupFailTimer = new FTimerHandle();

	bWasCollected = false;

	bIsDisplayTextSet = false;

	bDidItemPickupFail = false;

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
	//TriggerSphere->OnComponentEndOverlap.AddDynamic(this, &AItem::OnOverlapEnd);
	EndDelegate.BindUFunction(this, FName("OnOverlapEnd"));
	OnActorEndOverlap.Add( EndDelegate);
	TriggerSphereRadius = TriggerSphere->GetScaledSphereRadius() /4;
	
	
	
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

}

void AItem::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	IdleAnimation(DeltaSeconds);
	if (bDidItemPickupFail)
	{
		if (GetPickupFailTimer()->IsValid())
		{
			CantCollectAnimation(DeltaSeconds);
			if (GetPickupFailTimerElapsed() == -1.0f && GetPickupFailTimerRemaining() == -1.0f)
			{
				bDidItemPickupFail = false;
				GetPickupFailTimer()->Invalidate();
				
			}
		}
		

	}
	
	
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

bool AItem::DidItemPickupFail()
{
	return bDidItemPickupFail;
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

void AItem::CantCollectAnimation(float DeltaSeconds)
{
	SetActorLocation(FMath::Lerp(GetActorLocation(), BoundingVectors[FMath::RandRange(0, BoundingVectors.Num() - 1)], 0.5f));
	//UE_LOG(LogTemp, Warning, TEXT("DeltaSeconds: %f"), DeltaSeconds);

}



void AItem::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (Cast<ACharacter>(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("Beginning Overlap"));
		OriginalLocation = GetActorLocation();
		UE_LOG(LogTemp, Warning, TEXT("Original Location: %f"), OriginalLocation.X);
		//TODO: Add logic to check if user inventory is full
		//If inventory full, play full animation
		bDidItemPickupFail = true;

		SwitchCollision();

		if (!GetNoCollisionTimer()->IsValid())
		{
			GetWorldTimerManager().ValidateHandle(*NoCollisionTimer);
		}

		SetNoCollisionTimer(3.0f);

		if (!GetPickupFailTimer()->IsValid())
		{
			GetWorldTimerManager().ValidateHandle(*PickupFailTimer);
		}
		SetPickupFailTimer(0.5f);

		if (BoundingVectors.Num() == 0)
		{
			BoundingVectors.Push(FVector(OriginalLocation.X + TriggerSphereRadius, OriginalLocation.Y, OriginalLocation.Z));
			BoundingVectors.Push(FVector(OriginalLocation.X - TriggerSphereRadius, OriginalLocation.Y, OriginalLocation.Z));
			BoundingVectors.Push(FVector(OriginalLocation.X, OriginalLocation.Y + TriggerSphereRadius, OriginalLocation.Z));
			BoundingVectors.Push(FVector(OriginalLocation.X, OriginalLocation.Y - TriggerSphereRadius, OriginalLocation.Z));
		}
		//else collect item
	//	CollectItem();
	}
}

void AItem::SwitchCollision()
{
	//this->SetActorEnableCollision(!GetActorEnableCollision());
	//ItemMesh->bGenerateOverlapEvents = !(ItemMesh->bGenerateOverlapEvents);
	//TriggerSphere->bGenerateOverlapEvents = !TriggerSphere->bGenerateOverlapEvents;
}

void AItem::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("End Overlap"));
	if (Cast<ACharacter>(OtherActor))
	{

		if (GetNoCollisionTimerElapsed() == -1.0f && GetNoCollisionTimerRemaining() == -1.0f)
		{
			UE_LOG(LogTemp, Warning, TEXT("Switching collision because player went outside bounds"));
			SwitchCollision();
		}
	}
}

void AItem::CollectItem()
{
	
	bWasCollected = true;
	//this 'paragraph' will probably need to move to it's own function
	ItemMesh->SetHiddenInGame(!(ItemMesh->bHiddenInGame));
	this->SetActorEnableCollision(!GetActorEnableCollision());
	ItemMesh->bGenerateOverlapEvents = !(ItemMesh->bGenerateOverlapEvents);
	TriggerSphere->bGenerateOverlapEvents = !TriggerSphere->bGenerateOverlapEvents;
	//SetActorHiddenInGame(true);
	
	TriggerSphere->bHiddenInGame = true;
	SetActorTickEnabled(false);
	UGameplayStatics::PlaySound2D(GetWorld(), PickupSound);

	
	//UE_LOG(LogTemp, Warning, TEXT("Current Actor collision enabled: %s"), this->GetActorEnableCollision() ? TEXT("true") : TEXT("false"));
	
}

void AItem::SetNoCollisionTimer(float Duration)
{
	GetWorldTimerManager().SetTimer(*NoCollisionTimer, Duration, false);
}

FTimerHandle* AItem::GetNoCollisionTimer()
{
	return NoCollisionTimer;
}

float AItem::GetNoCollisionTimerElapsed()
{
	return GetWorldTimerManager().GetTimerElapsed(*NoCollisionTimer);
}

float AItem::GetNoCollisionTimerRemaining()
{
	return GetWorldTimerManager().GetTimerRemaining(*NoCollisionTimer);
}

void AItem::SetPickupFailTimer(float Duration)
{
	GetWorldTimerManager().SetTimer(*PickupFailTimer, Duration, false);
}

FTimerHandle * AItem::GetPickupFailTimer()
{
	return PickupFailTimer;
}

float AItem::GetPickupFailTimerElapsed()
{
	return GetWorldTimerManager().GetTimerElapsed(*PickupFailTimer);
}

float AItem::GetPickupFailTimerRemaining()
{
	return GetWorldTimerManager().GetTimerRemaining(*PickupFailTimer);
}

bool AItem::GetIsDisplayTextSet()
{
	return bIsDisplayTextSet;
}

void AItem::SetIsDisplayTextSet(bool NewState)
{
	bIsDisplayTextSet = NewState;
}



#undef LOCTEXT_NAMESPACE
