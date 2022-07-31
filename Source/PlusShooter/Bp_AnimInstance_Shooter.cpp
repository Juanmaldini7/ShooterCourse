#include "Bp_AnimInstance_Shooter.h"

void UBp_AnimInstance_Shooter::NativeUpdateAnimation(float delta) {
    BlendSpeed = GetOwningActor()->GetVelocity().Size() / 600;

}