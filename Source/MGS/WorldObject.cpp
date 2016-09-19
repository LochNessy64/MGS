// Fill out your copyright notice in the Description page of Project Settings.

#include "MGS.h"
#include "WorldObject.h"


// Sets default values
AWorldObject::AWorldObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	matSound = CreateDefaultSubobject<USoundBase>(TEXT("matSound"));

}

// Called when the game starts or when spawned
void AWorldObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWorldObject::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

USoundBase * AWorldObject::GetMatSound() {
	if (matSound) {
		return matSound;
	}
	else {
		return nullptr;
	}
}

void AWorldObject::SetMatSound(USoundBase *newSound) {
	matSound = newSound;
}