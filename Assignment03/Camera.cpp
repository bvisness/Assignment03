//
//  Camera.cpp
//  Assignment03
//
//  Created by Benjamin Visness on 10/1/15.
//  Copyright (c) 2015 Benjamin Visness. All rights reserved.
//

#include "Camera.h"

GameObject* defaultTarget;

Camera::Camera() {
    defaultTarget = new Empty();
    defaultTarget->position = Vector3(0, 0, 1);
    addChild(defaultTarget);
}

void Camera::setTarget(GameObject* target) {
    lookAtTarget = target;
}

void Camera::removeTarget() {
    lookAtTarget = nullptr;
}

Matrix4 Camera::getModelViewMatrix() {
    GameObject* targetToUse = lookAtTarget;
    if (lookAtTarget == nullptr) {
        targetToUse = defaultTarget;
    }
    
    if (position == targetToUse->position) {
        warnWithMessage("In Camera::getModelViewMatrix(): Camera in same position as lookAtTarget");
    }
    
    Vector4 up = RotateX(rotation.x) * Vector3(0, 1, 0);
    up = RotateY(rotation.y) * up;
    
    return LookAt(position, targetToUse->getWorldPosition(), up);
}
