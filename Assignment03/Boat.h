//
//  Boat.h
//  Assignment02
//
//  Created by Benjamin Visness on 9/28/15.
//  Copyright (c) 2015 Benjamin Visness. All rights reserved.
//

#ifndef __Assignment02__Boat__
#define __Assignment02__Boat__

#include "GameObject.h"
#include "GLMiddleman.h"

class Boat: public GameObject {
protected:
    int getNumberOfVertices();
    Vector4* getVertices();
    Vector4* getVertexColors();
};

#endif /* defined(__Assignment02__Boat__) */
