//
//  GameObject.cpp
//  Assignment02
//
//  Created by Benjamin Visness on 9/26/15.
//  Copyright (c) 2015 Benjamin Visness. All rights reserved.
//

#include "GameObject.h"
#include "Scene.h"

void GameObject::setScene(Scene* newScene) {
    scene = newScene;
    
    std::vector<GameObject*>::iterator it = children.begin();
    while (it != children.end()) {
        (*it)->setScene(newScene);
        it++;
    }
}

void GameObject::initGameObject() {
    if (scene == nullptr) {
        abortWithMessage("In GameObject::initGameObject(): Scene for GameObject was never set");
    }
    
    if (initialized) {
        return;
    }
    
    glGenVertexArrays(1, &vao);
    glGenBuffers(2, vbo);
    
    scene->middleman->bufferObject(vao, vbo, getNumberOfVertices(), getVertices(), getNumberOfVertices(), getVertexColors());
    
    std::vector<GameObject*>::iterator it = children.begin();
    while (it != children.end()) {
        (*it)->initGameObject();
        it++;
    }
    
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

Vector3 GameObject::getWorldPosition() {
    if (parent == nullptr) {
        return position;
    }
    
    Vector4 pos = getModelViewMatrix() * Vector4(0, 0, 0, 1);
    return Vector3(pos.x, pos.y, pos.z);
}

Vector3 GameObject::getWorldRotation() {
    if (parent == nullptr) {
        return rotation;
    }
    
    Vector3 parentRotation = parent->getWorldRotation();
    return Vector3(
        parentRotation.x + rotation.x,
        parentRotation.y + rotation.y,
        parentRotation.z + rotation.z
    );
}

GLfloat GameObject::getWorldScale() {
    if (parent == nullptr) {
        return scale;
    }
    
    return parent->getWorldScale() * scale;
}

mat4 GameObject::getModelViewMatrix() {
    mat4 mvMatrix;
    if (parent == nullptr) {
        Camera* camera = scene->getActiveCamera();
        if (camera == nullptr) {
            abortWithMessage("In GameObject::getModelViewMatrix(): Active camera for scene was nullptr");
        }
        mvMatrix = camera->getModelViewMatrix();
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
    if (scene == nullptr) {
        abortWithMessage("In GameObject::draw(): Scene for GameObject was never set");
    }
    
    mat4 mv = getModelViewMatrix();
    
    scene->middleman->updateModelViewMatrix(mv);
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, getNumberOfVertices());
    
    std::vector<GameObject*>::iterator it = children.begin();
    while (it != children.end()) {
        (*it)->draw();
        it++;
    }
}
