//
//  Camera.cpp
//  Assignment03
//
//  Created by Benjamin Visness on 10/1/15.
//  Copyright (c) 2015 Benjamin Visness. All rights reserved.
//

#include "Camera.h"

void Camera::setTarget(GameObject* target) {
    lookAtTarget = target;
}

Matrix4 Camera::getModelViewMatrix() {
    if (position == lookAtTarget->position) {
        warnWithMessage("In Camera::getModelViewMatrix(): Camera in same position as lookAtTarget");
    }
    
    return LookAt(position, lookAtTarget->position, Vector3(0, 1, 0));
}
