//
//  Rudder.cpp
//  Assignment02
//
//  Created by Benjamin Visness on 9/30/15.
//  Copyright (c) 2015 Benjamin Visness. All rights reserved.
//

#include "Rudder.h"

const GLfloat rudderHeight = 2;
const GLfloat rudderDepth = 0.5;

const int numVertsRudder = 6;

Vector4 rudderVerts[numVertsRudder];
Vector4 rudderColors[numVertsRudder];

void Rudder::initRudder() {
    for(int i=0; i<6; i++){
        rudderColors[i] = rudderColor; //bottom
    }
    
    rudderVerts[0] = Vector4(0, 0, 0, 1.0);
    rudderVerts[1] = Vector4(0, 0, -rudderDepth, 1.0);
    rudderVerts[2] = Vector4(0, rudderHeight, 0, 1.0);
    rudderVerts[3] = Vector4(0, rudderHeight, 0, 1.0);
    rudderVerts[4] = Vector4(0, 0, -rudderDepth, 1.0);
    rudderVerts[5] = Vector4(0, rudderHeight, -rudderDepth, 1.0);
}

int Rudder::getNumberOfVertices() {
    return numVertsRudder;
}

Vector4* Rudder::getVertices() {
    initRudder();
    return rudderVerts;
}

Vector4* Rudder::getVertexColors() {
    initRudder();
    return rudderColors;
}
