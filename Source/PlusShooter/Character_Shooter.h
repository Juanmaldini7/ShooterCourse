#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Character_Shooter.generated.h"

UCLASS()
class PLUSSHOOTER_API ACharacter_Shooter : public ACharacter
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveForwardIntensity = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveRightIntensity = 100;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector InitialLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FRotator InitialRotation;

	float InitialLife = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Life = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LifeMax = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RespawnLife = 3;

void SetupPlayerInputComponent(class UInputComponent* inputcomponent) override;
void MoveForward(float value);
void MoveRight(float value);	 
void Tick(float deltaTime) override; 

ACharacter_Shooter();

protected:
	 void BeginPlay() override;
};
