// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "MGS.h"
#include "InventoryUserWidget.h"
#include "MyPlayerController.h"
#include "MGSCharacter.h"

//////////////////////////////////////////////////////////////////////////
// AMGSCharacter

#define MAX_INVENTORY_ITEMS 4

void AMGSCharacter::BeginPlay()
{
	Super::BeginPlay();

	Inventory.SetNum(MAX_INVENTORY_ITEMS);
	if (InventoryWidgetBP)
	{
		if (!InventoryWidget)
		{
			InventoryWidget = CreateWidget <UInventoryWidget>(GetWorld(), InventoryWidgetBP);
			if (!InventoryWidget)
				return;
			//nventoryWidget->AddToViewport();
			//InventoryWidget->SetVisibility(ESlateVisibility::Hidden); //set it to hidden to not open on spawn
		}
	}

	UIItem *BlankUIItem = NewObject<UIItem>();
	BlankUIItem->SetUIItemName("None");
	Inventory.Add(BlankUIItem);

	//Initial value
	bIsInventoryOpen = false;
}

AMGSCharacter::AMGSCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	InvKeyHoldTime = 0.0f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	bShowingInventory = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void AMGSCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// Set up gameplay key bindings
	check(InputComponent);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	InputComponent->BindAction("OpenMenu", IE_Pressed, this, &AMGSCharacter::ShowInventory);
	InputComponent->BindAction("OpenMenu", IE_Released, this, &AMGSCharacter::HideInventory);

	InputComponent->BindAxis("MoveForward", this, &AMGSCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMGSCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &AMGSCharacter::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &AMGSCharacter::LookUpAtRate);

	// handle touch devices
	InputComponent->BindTouch(IE_Pressed, this, &AMGSCharacter::TouchStarted);
	InputComponent->BindTouch(IE_Released, this, &AMGSCharacter::TouchStopped);
	InputComponent->BindAction("Inventory", IE_Pressed, this, &AMGSCharacter::HandleInventoryInput);
}


void AMGSCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	// jump, but only on the first touch
	if (FingerIndex == ETouchIndex::Touch1)
	{
		Jump();
	}
}

void AMGSCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	if (FingerIndex == ETouchIndex::Touch1)
	{
		StopJumping();
	}
}

void AMGSCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMGSCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AMGSCharacter::HandleInventoryInput()
{
	AMyPlayerController *Con = Cast<AMyPlayerController>(GetController());
	if (Con)
	{
		Con->HandleInventoryInput();
	}

}

void AMGSCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AMGSCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void AMGSCharacter::ShowInventory()
{
	InvKeyHoldTime = 0.0f;
	bShowingInventory = true;
	
	UE_LOG(LogTemp, Warning, TEXT("Inventory should be visible"))
	InventoryWidget->Show();
	//InventoryWidget->SetVisibility(ESlateVisibility::Visible);

}

void AMGSCharacter::HideInventory()
{
	InvKeyHoldTime = 0.0f;
	bShowingInventory = false;
	UE_LOG(LogTemp, Warning, TEXT("Inventory should be hidden"))
	InventoryWidget->Hide();
	//InventoryWidget->SetVisibility(ESlateVisibility::Hidden);
}