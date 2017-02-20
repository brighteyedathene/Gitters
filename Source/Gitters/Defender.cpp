
#include "Gitters.h"
#include "Defender.h"


// Sets default values
ADefender::ADefender()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set up components - maybe later I can attach a gun barrel to here for lasers to spawn at
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	
	// Take control of the default player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	Lives = 3;
	DamagePerHit = 1;
	
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
	
	GLog->Log("Tick");

	// Handle movement
	{
		if (MovementInput != 0)
		{
			GLog->Log("Tock");
			FVector NewLocation = GetActorLocation();
			NewLocation += GetActorRightVector() * MovementInput * DeltaTime;
			SetActorLocation(NewLocation);
		}
	}

}

// Input functions
// Bind functions to Input
void ADefender::SetupPlayerInputComponent(class UInputComponent* InputComponent) {
	//Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAction("Shoot", IE_Pressed, this, &ADefender::Shoot);
	InputComponent->BindAxis("MovementX", this, &ADefender::Move);
}

void ADefender::Move(float AxisValue) {
	MovementInput = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}

void ADefender::Shoot() {
	ShootInput = true;
}