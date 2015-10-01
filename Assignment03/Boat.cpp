//
//  Boat.cpp
//  Assignment02
//
//  Created by Benjamin Visness on 9/28/15.
//  Copyright (c) 2015 Benjamin Visness. All rights reserved.
//

#include "Boat.h"

const int numVertsBoat = 36;

Vector4 boatVerts[numVertsBoat];
Vector4 boatColors[numVertsBoat];

void initBoat() {
    for(int i=0; i<6; i++){
        boatColors[i] = Vector4(0.0, 1.0, 1.0, 1.0); //front
    }
    boatVerts[0] = Vector4(1.0, 0, 1.0, 1.0);
    boatVerts[1] = Vector4(1.0, 1.0, 2.0, 1.0);
    boatVerts[2] = Vector4(-1.0, 1.0, 2.0, 1.0);
    boatVerts[3] = Vector4(-1.0, 1.0, 2.0, 1.0);
    boatVerts[4] = Vector4(-1.0, 0, 1.0, 1.0);
    boatVerts[5] = Vector4(1.0, 0, 1.0, 1.0);
    
    
    for(int i=6; i<12; i++){
        boatColors[i] = Vector4(1.0, 0.0, 1.0, 1.0); //back
    }
    boatVerts[6] = Vector4(-1.0, 0, -1.0, 1.0);
    boatVerts[7] = Vector4(-1.0, 1.0, -1.0, 1.0);
    boatVerts[8] = Vector4(1.0, 1.0, -1.0, 1.0);
    boatVerts[9] = Vector4(1.0, 1.0, -1.0, 1.0);
    boatVerts[10] = Vector4(1.0, 0, -1.0, 1.0);
    boatVerts[11] = Vector4(-1.0, 0, -1.0, 1.0);
    
    for(int i=12; i<18; i++){
        boatColors[i] = Vector4(1.0, 1.0, 0.0, 1.0); //left
    }
    boatVerts[12] = Vector4(1.0, 1.0, -1.0, 1.0);
    boatVerts[13] = Vector4(1.0, 0, -1.0, 1.0);
    boatVerts[14] = Vector4(1.0, 0, 1.0, 1.0);
    boatVerts[15] = Vector4(1.0, 0, 1.0, 1.0);
    boatVerts[16] = Vector4(1.0, 1.0, 2.0, 1.0);
    boatVerts[17] = Vector4(1.0, 1.0, -1.0, 1.0);
    
    for(int i=18; i<24; i++){
        boatColors[i] = Vector4(1.0, 0.0, 0.0, 1.0); //right
    }
    boatVerts[18] = Vector4(-1.0, 1.0, -1.0, 1.0);
    boatVerts[19] = Vector4(-1.0, 0, -1.0, 1.0);
    boatVerts[20] = Vector4(-1.0, 0, 1.0, 1.0);
    boatVerts[21] = Vector4(-1.0, 0, 1.0, 1.0);
    boatVerts[22] = Vector4(-1.0, 1.0, 2.0, 1.0);
    boatVerts[23] = Vector4(-1.0, 1.0, -1.0, 1.0);
    
    for(int i=24; i<30; i++){
        boatColors[i] = Vector4(0.0, 0.0, 1.0, 1.0); //top
    }
    boatVerts[24] = Vector4(1.0, 1.0, 2.0, 1.0);
    boatVerts[25] = Vector4(1.0, 1.0, -1.0, 1.0);
    boatVerts[26] = Vector4(-1.0, 1.0, -1.0, 1.0);
    boatVerts[27] = Vector4(-1.0, 1.0, -1.0, 1.0);
    boatVerts[28] = Vector4(-1.0, 1.0, 2.0, 1.0);
    boatVerts[29] = Vector4(1.0, 1.0, 2.0, 1.0);
    
    for(int i=30; i<36; i++){
        boatColors[i] = Vector4(0.0, 1.0, 0.0, 1.0); //bottom
    }
    boatVerts[30] = Vector4(1.0, 0, -1.0, 1.0);
    boatVerts[31] = Vector4(1.0, 0, 1.0, 1.0);
    boatVerts[32] = Vector4(-1.0, 0, 1.0, 1.0);
    boatVerts[33] = Vector4(-1.0, 0, 1.0, 1.0);
    boatVerts[34] = Vector4(-1.0, 0, -1.0, 1.0);
    boatVerts[35] = Vector4(1.0, 0, -1.0, 1.0);
}

int Boat::getNumberOfVertices() {
    return numVertsBoat;
}

Vector4* Boat::getVertices() {
    initBoat();
    return boatVerts;
}

Vector4* Boat::getVertexColors() {
    initBoat();
    return boatColors;
}
