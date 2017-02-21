
#include "Gitters.h"
#include "Defender.h"


// My General Log
DEFINE_LOG_CATEGORY(MyLog); // macro FUNCTION, not a method therefore -- requires ';'
//UE_LOG(MyLog, Warning, TEXT("BLABLABLA")); //Example log
//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, "BLABLABLA"); //This one prints to screen

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
	SetupPlayerInputComponent(Super::InputComponent);
	//UE_LOG(MyLog, Warning, TEXT("BeginPlay"));

}

// Called every frame
void ADefender::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	check(GEngine);

	//String pos = GetActorLocation().ToString();
	GEngine->AddOnScreenDebugMessage(-1, 0.3f, FColor::Red, GetActorLocation().ToString());

	// Handle movement
	{
		if (MovementInput != 0)
		{
			UE_LOG(MyLog, Warning, TEXT("Movement wasn't 0"));
			FVector NewLocation = GetActorLocation();

			NewLocation += GetActorRightVector() * MovementInput * DeltaTime;
			GEngine->AddOnScreenDebugMessage(-1, 0.3f, FColor::Green, NewLocation.ToString());
			SetActorLocation(NewLocation);
		}
	}

}

// Input functions
// Bind functions to Input
void ADefender::SetupPlayerInputComponent(class UInputComponent* inputComponent) {
	Super::SetupPlayerInputComponent(inputComponent);
	UE_LOG(MyLog, Warning, TEXT("Setup player input! said ADefender"));
	check(InputComponent);

	InputComponent->BindAction("Shoot", IE_Pressed, this, &ADefender::Shoot);
	InputComponent->BindAxis("MovementX", this, &ADefender::Move);
}

void ADefender::Move(float AxisValue) {
	MovementInput = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}

void ADefender::Shoot() {
	ShootInput = true;
}