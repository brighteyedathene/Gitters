
#pragma once

#include "GameFramework/Pawn.h"
#include "Defender.generated.h"

UCLASS()
class GITTERS_API ADefender : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Defender")
	int32 Lives;

	UPROPERTY(EditAnywhere, Category = "Defender")
	int32 DamagePerHit;

	
public:	
	// Sets default values for this actor's properties
	ADefender();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	// Sprite for the defender ship's body
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Defender", meta = (AllowPrivateAccess = "true"))
	//class UPaperSpriteComponent* DefenderSprite;
	
protected:
	// Input variables
	float MovementInput;
	bool ShootInput;

	// Input functions
	void Move(float AxisValue);
	void Shoot();
	
};
