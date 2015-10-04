//
//  Scene.h
//  Assignment03
//
//  Created by Benjamin Visness on 10/1/15.
//  Copyright (c) 2015 Benjamin Visness. All rights reserved.
//

#ifndef __Assignment03__Scene__
#define __Assignment03__Scene__

#include <vector>

#include "GameObject.h"
#include "Camera.h"

class Scene {
protected:
    std::vector<GameObject*> gameObjects = std::vector<GameObject*>();
    Camera* activeCamera = nullptr;
    bool initialized = false;
public:
    GLMiddleman* middleman = nullptr;
    Scene(GLMiddleman* newMiddleman);
    
    void addGameObject(GameObject* obj);
    void init();
    void draw();
    
    Camera* getActiveCamera();
    void setActiveCamera(Camera* cam);
};

#endif /* defined(__Assignment03__Scene__) */
