//
//  Camera.h
//  Assignment03
//
//  Created by Benjamin Visness on 10/1/15.
//  Copyright (c) 2015 Benjamin Visness. All rights reserved.
//

#ifndef __Assignment03__Camera__
#define __Assignment03__Camera__

#include "VisnessUtil.h"
#include "Empty.h"

class Camera: public Empty {
private:
    void updateSceneProjectionMatrixIfSafe();
protected:
    GameObject* lookAtTarget = nullptr;
    GLfloat fov = 45;
    GLfloat near = 1;
    GLfloat far = 100;
public:
    Camera();
    GameObject* getTarget();
    void setTarget(GameObject* target);
    void removeTarget();
    Matrix4 getModelViewMatrix();
    Matrix4 getProjectionMatrix();
    
    GLfloat getFOV();
    void setFOV(GLfloat newFOV);
    void setNearClippingDistance(GLfloat newNear);
    void setFarClippingDistance(GLfloat newFar);
};

#endif /* defined(__Assignment03__Camera__) */
