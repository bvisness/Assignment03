//
//  VisnessUtil.cpp
//  Assignment01
//
//  Created by Benjamin Visness on 9/9/15.
//  Copyright (c) 2015 Benjamin Visness. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>

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

void warnWithMessage(const char* msg) {
    printf("WARNING: %s\n", msg);
}

void abortWithMessage(const char* msg) {
    printf("ERROR: %s\n", msg);
    abort();
}

bool operator==(const Vector2& lhs, const Vector2& rhs) {
    return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}

bool operator==(const Vector3& lhs, const Vector3& rhs) {
    return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z);
}

bool operator==(const Vector4& lhs, const Vector4& rhs) {
    return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z) && (lhs.w == rhs.w);
}
