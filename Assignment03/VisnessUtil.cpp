//
//  VisnessUtil.cpp
//  Assignment01
//
//  Created by Benjamin Visness on 9/9/15.
//  Copyright (c) 2015 Benjamin Visness. All rights reserved.
//

#include <stdlib.h>

#include "VisnessUtil.h"

GLfloat randRange(GLfloat min, GLfloat max) {
    return ((GLfloat)rand() / RAND_MAX) * (max - min) + min;
}

GLfloat clamp(GLfloat n, GLfloat min, GLfloat max) {
    if (n < min) {
        return min;
    }
    if (n > max) {
        return max;
    }
    
    return n;
}
