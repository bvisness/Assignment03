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

class Scene;

class GameObject {
friend class Scene;
protected:
    bool initialized = false;
    Scene* scene = nullptr;
    void initGameObject();
    
    GLuint vao;
    GLuint vbo[2];
    GameObject* parent = nullptr;
    std::vector<GameObject*> children = std::vector<GameObject*>();
    
    virtual int getNumberOfVertices() = 0;
    virtual Vector4* getVertices() = 0;
    virtual Vector4* getVertexColors() = 0;
public:
    void setScene(Scene* newScene);
    
    GLuint getVAO();
    
    Vector3 position = Vector3();
    Vector3 rotation = Vector3();
    GLfloat scale = 1;
    
    GameObject* getParent();
    std::vector<GameObject*> getChildren();
    void addChild(GameObject* obj);
    
    Vector3 getWorldPosition();
    Vector3 getWorldRotation();
    GLfloat getWorldScale();
    mat4 getModelViewMatrix();
    void draw();
};

#endif
