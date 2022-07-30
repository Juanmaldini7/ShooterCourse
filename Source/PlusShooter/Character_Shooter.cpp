#include "Character_Shooter.h"
#include "Engine/World.h"
#include "Components/InputComponent.h"

ACharacter_Shooter::ACharacter_Shooter() {
	PrimaryActorTick.bCanEverTick = true;
}

void ACharacter_Shooter::BeginPlay() {
	Super::BeginPlay();
	InitialLocation = GetActorLocation();
	InitialRotation = GetActorRotation();
	InitialLife = Life;
}

void ACharacter_Shooter::MoveForward(float value) {
	float DeltaTime = GetWorld()->GetDeltaSeconds();
	AddActorLocalOffset(FVector(value * MoveForwardIntensity * DeltaTime, 0, 0));
}

void ACharacter_Shooter::MoveRight(float value) {
	float DeltaTime = GetWorld()->GetDeltaSeconds();
	AddActorLocalOffset(FVector(0, value* MoveRightIntensity * DeltaTime, 0));
}

void ACharacter_Shooter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	InputComponent->BindAxis("MoveForward", this, &ACharacter_Shooter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACharacter_Shooter::MoveRight);
	Super::SetupPlayerInputComponent(PlayerInputComponent);
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