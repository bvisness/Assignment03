//
//  FanBlade.h
//  Assignment02
//
//  Created by Benjamin Visness on 9/30/15.
//  Copyright (c) 2015 Benjamin Visness. All rights reserved.
//

#ifndef __Assignment02__FanBlade__
#define __Assignment02__FanBlade__

#include "GameObject.h"

class FanBlade: public GameObject {
private:
    void initBlade();
    Vector4 bladeColor;
protected:
    int getNumberOfVertices();
    Vector4* getVertices();
    Vector4* getVertexColors();
public:
    FanBlade(Vector4 color) : GameObject() {
        bladeColor = color;
    }
};

#endif /* defined(__Assignment02__FanBlade__) */
