//
//  VisnessUtil.h
//  Assignment01
//
//  Created by Benjamin Visness on 9/9/15.
//  Copyright (c) 2015 Benjamin Visness. All rights reserved.
//

#ifndef __VISNESSUTIL_H__
#define __VISNESSUTIL_H__

#include "VisnessGL.h"
#include "Angel.h"

#ifndef DEG_TO_RAD
#define DEG_TO_RAD 0.0174532925
#endif

#ifndef RAD_TO_DEG
#define RAD_TO_DEG 57.2957795
#endif

typedef vec2 Vector2;
typedef vec2 Point2;

typedef vec3 Vector3;
typedef vec3 Point3;

typedef vec4 Vector4;

GLfloat randRange(GLfloat min, GLfloat max);

GLfloat clamp(GLfloat n, GLfloat min, GLfloat max);

#endif
