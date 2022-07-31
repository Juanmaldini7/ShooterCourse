#include "Bp_AnimInstance_Shooter.h"

void UBp_AnimInstance_Shooter::NativeUpdateAnimation(float delta) {
    BlendSpeed = GetOwningActor()->GetVelocity().Size() / 600;
    int VerticalSpeed = GetOwningActor()->GetVelocity().Z;
    if (VerticalSpeed == 0) {
        IsJumping = false;
    }
    else {
            IsJumping = true;
    }
}