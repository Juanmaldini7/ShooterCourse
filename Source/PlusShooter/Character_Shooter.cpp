#include "Character_Shooter.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"

ACharacter_Shooter::ACharacter_Shooter() {
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	camera->bUsePawnControlRotation = true;
	camera->SetupAttachment(GetRootComponent());

	arms = CreateDefaultSubobject<USkeletalMeshComponent>("Arms");
	arms->SetupAttachment(camera);

	weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	weapon->SetupAttachment(arms, "GripPoint");
}

void ACharacter_Shooter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	InputComponent->BindAxis("MoveForward", this, &ACharacter_Shooter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACharacter_Shooter::MoveRight);
	InputComponent->BindAxis("Turn", this, &ACharacter_Shooter::RotateYaw);
	InputComponent->BindAxis("LookUp", this, &ACharacter_Shooter::RotatePitch);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter_Shooter::StartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter_Shooter::StopJump);
	InputComponent->BindAction("Fire", IE_Pressed, this, &ACharacter_Shooter::StartFire);
	InputComponent->BindAction("Fire", IE_Released, this, &ACharacter_Shooter::StopFire);
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

void ACharacter_Shooter::StartFire() {
	IsFiring = true;
}

void ACharacter_Shooter::StopFire() {
	IsFiring = false;
}
