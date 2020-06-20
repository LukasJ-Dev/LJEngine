//
// Created by Lukas on 2020-06-09.
//

#include "ScriptRegistrations.h"
#include <rttr/registration.h>
#include <Scene/Objects/RigidBody.h>

RTTR_REGISTRATION {
    rttr::registration::class_<RigidBody>("rigidbody")
            .method("Move", &RigidBody::Move);
}