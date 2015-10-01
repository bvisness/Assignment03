//
//  FanBlade.cpp
//  Assignment02
//
//  Created by Benjamin Visness on 9/30/15.
//  Copyright (c) 2015 Benjamin Visness. All rights reserved.
//

#include "FanBlade.h"

const GLfloat bladeOffset = 0.25;
const GLfloat bladeLength = 1;
const GLfloat bladeWidth = 0.35;

const int numVertsBlade = 6;

Vector4 bladeColor;

Vector4 bladeVerts[numVertsBlade];
Vector4 bladeColors[numVertsBlade];

void FanBlade::initGameObject(Vector4 color) {
    bladeColor = color;
    GameObject::initGameObject();
}

void initBlade() {
    for(int i=0; i<6; i++){
        bladeColors[i] = bladeColor;
    }
    
    bladeVerts[0] = Vector4(bladeOffset, bladeWidth / 2, 0, 1);
    bladeVerts[1] = Vector4(bladeOffset, -bladeWidth / 2, 0, 1);
    bladeVerts[2] = Vector4(bladeOffset + bladeLength, bladeWidth / 2, 0, 1);
    bladeVerts[3] = Vector4(bladeOffset + bladeLength, bladeWidth / 2, 0, 1);
    bladeVerts[4] = Vector4(bladeOffset, -bladeWidth / 2, 0, 1);
    bladeVerts[5] = Vector4(bladeOffset + bladeLength, -bladeWidth / 2, 0, 1);
}

int FanBlade::getNumberOfVertices() {
    return numVertsBlade;
}

Vector4* FanBlade::getVertices() {
    initBlade();
    return bladeVerts;
}

Vector4* FanBlade::getVertexColors() {
    initBlade();
    return bladeColors;
}
