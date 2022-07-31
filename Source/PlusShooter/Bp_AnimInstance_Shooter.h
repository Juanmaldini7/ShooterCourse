#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Bp_AnimInstance_Shooter.generated.h"

UCLASS()
class PLUSSHOOTER_API UBp_AnimInstance_Shooter : public UAnimInstance
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BlendSpeed;
	void NativeUpdateAnimation(float delta)  override;
};
 