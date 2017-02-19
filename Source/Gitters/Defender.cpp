// Fill out your copyright notice in the Description page of Project Settings.

#include "Gitters.h"
#include "Defender.h"


// Sets default values
ADefender::ADefender()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Lives = 3;
	DamagePerHit = 1;

	if(!RootComponent) {
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefenderBase");
	}

	DefenderSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("DefenderSprite"));
	DefenderSprite->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void ADefender::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADefender::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

