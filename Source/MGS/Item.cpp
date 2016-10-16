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

	ItemTextBlock = nullptr;

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
	
	//UE_LOG(LogTemp, Warning, TEXT("Can Ever Tick? : %s"), PrimaryActorTick.bCanEverTick ? TEXT("True") : TEXT("False"));
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	if (wText)
	{
		TextWidget = CreateWidget<UUserWidget>(GetWorld(), wText);

		if (TextWidget)
		{
			const FName TextControlName = FName(TEXT("UMGItemTextBlock"));
			((UTextBlock*)(TextWidget->WidgetTree->FindWidget(TextControlName)))->Text = FText::FromString("CAN YOU SEE ME NOW BITCH?");
			TextWidget->WidgetTree->FindWidget(TextControlName)->bIsEnabled = true;
			//TextWidget->Re
			ItemTextBlock = (UTextBlock*)(TextWidget->WidgetTree->FindWidget(TextControlName));

			
			//TextWidget->SetVisibility(ESlateVisibility::Visible);
			//TextWidget->SetPositionInViewport()
			UCanvasPanelSlot *canvasSlot = UWidgetLayoutLibrary::SlotAsCanvasSlot(ItemTextBlock);

			TextWidget->AddToViewport();
			FLinearColor TextColorOpacity = TextWidget->ColorAndOpacity;
			FVector2D TextPosition = canvasSlot->GetPosition();
			//TextWidget->
			TextWidget->WidgetTree->FindWidget(FName(TEXT("CanvasPanel_0")));
			UE_LOG(LogTemp, Warning, TEXT("Text Widget has been created."));
			UE_LOG(LogTemp, Warning, TEXT("Text Widget visibility is: %s"), ItemTextBlock->bIsEnabled ? TEXT("ON") : TEXT("OFF"));
			UE_LOG(LogTemp, Warning, TEXT("Text Widget position is: x= %f y= %f"), TextPosition.X, TextPosition.Y);
			UE_LOG(LogTemp, Warning, TEXT("Text Widget text is: %s"), *ItemTextBlock->Text.ToString());
			UE_LOG(LogTemp, Warning, TEXT("TextWidget Color and Opacity is: A= %f B= %f G= %f R= %f"), TextColorOpacity.A, TextColorOpacity.B, TextColorOpacity.G, TextColorOpacity.R);
		}
	}
}

void AItem::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	TextWidget->SetPositionInViewport(FVector2D(TurnRate.Yaw*DeltaSeconds, TurnRate.Pitch*DeltaSeconds));
	TextWidget->SetColorAndOpacity(FLinearColor(DeltaSeconds, DeltaSeconds, DeltaSeconds));
	//TextWidget->WidgetTree->FindWidget(FName(TEXT("UMGItemTextBlock")))->Set
	//UE_LOG(LogTemp, Warning, TEXT("Text Widget position is: x= %f y= %f"), TextPosition.X, TextPosition.Y);
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
	bWasCollected = true;
	this->SetActorEnableCollision(false);
	ItemMesh->bGenerateOverlapEvents = false;
	ItemMesh->SetHiddenInGame(true);
//	Canvas->DrawText(JLog, ItemName,ItemMesh->GetComponentLocation().X, ItemMesh->GetComponentLocation().Y)
	//SetActorHiddenInGame(true);
	TriggerSphere->bGenerateOverlapEvents = false;
	TriggerSphere->bHiddenInGame = true;
	SetActorTickEnabled(false);
	UGameplayStatics::PlaySound2D(OtherActor->GetWorld(), PickupSound);
	UE_LOG(LogTemp, Warning, TEXT("Current Actor collision enabled: %s"), this->GetActorEnableCollision() ? TEXT("true") : TEXT("false"));
	//TextWidget->Draw
}

#undef LOCTEXT_NAMESPACE
