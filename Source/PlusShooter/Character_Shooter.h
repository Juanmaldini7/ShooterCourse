#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Character_Shooter.generated.h"

UCLASS()
class PLUSSHOOTER_API ACharacter_Shooter : public ACharacter
{
	GENERATED_BODY()

private:

	void MoveForward(float value);
	void MoveRight(float value);
	void RotateYaw(float value);
	void RotatePitch(float value);	
	void StartJump();
	void StopJump();
	void StartFire();
	void StopFire();

public:

	ACharacter_Shooter();

	float InitialLife = 100;
	FRotator InitialRotation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsFiring;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector InitialLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveForwardIntensity = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveRightIntensity = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationIntensity = 60;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Life = 100;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float LifeMax = 100;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float RespawnLife = 3;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* camera;
	
	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* arms;

	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* weapon;

	void SetupPlayerInputComponent(class UInputComponent* inputcomponent) override;

	void BeginPlay() override;


};
