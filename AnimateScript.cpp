#include "AnimateScript.hpp"

AnimateScript::AnimateScript() {
    cube = std::make_shared<Cube>(20);
    cube->translate(0.0,0.0f,0.5f);
    cube->scale(0.5,0.2,0.1);
    rspeed1 = Quaternion(0.01f,-1.0f,1.0f,0.0f);
    rspeed2 = Quaternion(0.03f, 1.0f,-1.0f,1.0f);
    
    renderer::addRenderable(cube);
}

void AnimateScript::update(float time) {
    cube->rotate(rspeed1);
    cube->localRotate(rspeed2);
}
