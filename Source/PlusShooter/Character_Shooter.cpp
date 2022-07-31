#include "Character_Shooter.h"
#include "Engine/World.h"
#include "Components/InputComponent.h"

ACharacter_Shooter::ACharacter_Shooter() {
	PrimaryActorTick.bCanEverTick = true;
}

void ACharacter_Shooter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	InputComponent->BindAxis("MoveForward", this, &ACharacter_Shooter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACharacter_Shooter::MoveRight);
	InputComponent->BindAxis("Turn", this, &ACharacter_Shooter::RotateYaw);
	InputComponent->BindAxis("LookUp", this, &ACharacter_Shooter::RotatePitch);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter_Shooter::StartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter_Shooter::StopJump);
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ACharacter_Shooter::BeginPlay() {
	Super::BeginPlay();
	InitialLocation = GetActorLocation();
	InitialRotation = GetActorRotation();
	InitialLife = Life;
}

void ACharacter_Shooter::MoveForward(float value) {
	AddMovementInput(GetActorForwardVector(), value);
}

void ACharacter_Shooter::MoveRight(float value) {
	AddMovementInput(GetActorRightVector(), value);
}

void ACharacter_Shooter::RotateYaw(float value) {
	AddControllerYawInput(value * RotationIntensity * GetWorld()->GetDeltaSeconds());
}

void ACharacter_Shooter::RotatePitch(float value) {
	AddControllerPitchInput(value * RotationIntensity * GetWorld()->GetDeltaSeconds());
}

void ACharacter_Shooter::StartJump() {
	Jump();
}

void ACharacter_Shooter::StopJump() {
	StopJumping();
}

void ACharacter_Shooter::Tick(float deltaTime) {
	if (Life <= 0) {
		if (RespawnLife > 0) {
			
			SetActorLocation(InitialLocation);
			SetActorRotation(InitialRotation);
			RespawnLife--;
			Life = InitialLife;
		}
		else {
			Destroy();
		}
	}
}