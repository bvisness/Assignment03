//
//  Rudder.h
//  Assignment02
//
//  Created by Benjamin Visness on 9/30/15.
//  Copyright (c) 2015 Benjamin Visness. All rights reserved.
//

#ifndef __Assignment02__Rudder__
#define __Assignment02__Rudder__

#include "GameObject.h"
#include "GLMiddleman.h"

class Rudder: public GameObject {
private:
    void initRudder();
    Vector4 rudderColor;
protected:
    int getNumberOfVertices();
    Vector4* getVertices();
    Vector4* getVertexColors();
public:
    Rudder(Vector4 color) : GameObject() {
        rudderColor = color;
    }
};

#endif /* defined(__Assignment02__Rudder__) */
