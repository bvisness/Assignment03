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
protected:
    GameObject* lookAtTarget = nullptr;
public:
    Camera();
    void setTarget(GameObject* target);
    void removeTarget();
    Matrix4 getModelViewMatrix();
};

#endif /* defined(__Assignment03__Camera__) */
