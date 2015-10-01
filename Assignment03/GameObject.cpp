//
//  GameObject.cpp
//  Assignment02
//
//  Created by Benjamin Visness on 9/26/15.
//  Copyright (c) 2015 Benjamin Visness. All rights reserved.
//

#include "GameObject.h"

GameObject::GameObject(GLMiddleman* middleman) {
    position = Vector3();
    rotation = Vector3();
    scale = 1;
    parent = nullptr;
    children = std::vector<GameObject*>();
}

void GameObject::initGameObject() {
    if (initialized) {
        return;
    }
    
    glGenVertexArrays(1, &vao);
    glGenBuffers(2, vbo);
    
    middleman->bufferObject(vao, vbo, getNumberOfVertices(), getVertices(), getNumberOfVertices(), getVertexColors());
    
    initialized = true;
}

GLuint GameObject::getVAO() {
    return vao;
}

std::vector<GameObject*> GameObject::getChildren() {
    return children;
}

void GameObject::addChild(GameObject* obj) {
    obj->parent = this;
    children.push_back(obj);
}

GameObject* GameObject::getParent() {
    return parent;
}

mat4 GameObject::getModelViewMatrix() {
    mat4 mvMatrix;
    if (parent == nullptr) {
        mvMatrix = LookAt(vec4(0, 10, 20, 1.0), vec4(0, 0, 0, 1.0), vec4(0, 1, 0, 0.0));
    } else {
        mvMatrix = parent->getModelViewMatrix();
    }
    
    mvMatrix *= Translate(position.x, position.y, position.z);
    mvMatrix *= RotateZ(rotation.z);
    mvMatrix *= RotateY(rotation.y);
    mvMatrix *= RotateX(rotation.x);
    mvMatrix *= Scale(scale, scale, scale);
    
    return mvMatrix;
}

void GameObject::draw() {
    mat4 mv = getModelViewMatrix();
    
    middleman->updateModelViewMatrix(mv);
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, getNumberOfVertices());
    
    std::vector<GameObject*>::iterator it = children.begin();
    while (it != children.end()) {
        (*it)->draw();
        it++;
    }
}
