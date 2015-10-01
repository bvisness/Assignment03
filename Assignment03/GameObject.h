//
//  GameObject.h
//  Assignment02
//
//  Created by Benjamin Visness on 9/26/15.
//  Copyright (c) 2015 Benjamin Visness. All rights reserved.
//

#ifndef __Assignment02__GameObject__
#define __Assignment02__GameObject__

#include <vector>

#include "VisnessUtil.h"
#include "VisnessGL.h"
#include "Angel.h"
#include "GLMiddleman.h"

class GameObject {
protected:
    bool initialized = false;
    GLMiddleman* middleman;
    
    GLuint vao;
    GLuint vbo[2];
    GameObject* parent;
    std::vector<GameObject*> children;
    
    virtual int getNumberOfVertices() = 0;
    virtual Vector4* getVertices() = 0;
    virtual Vector4* getVertexColors() = 0;
public:
    GameObject(GLMiddleman* middleman);
    void initGameObject();
    
    GLuint getVAO();
    
    Vector3 position;
    Vector3 rotation;
    GLfloat scale;
    
    GameObject* getParent();
    std::vector<GameObject*> getChildren();
    void addChild(GameObject* obj);
    
    mat4 getModelViewMatrix();
    void draw();
};

#endif
