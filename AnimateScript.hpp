#ifndef __ANIMATESCRIPT_H
#define __ANIMATESCRIPT_H

#include "Renderer.hpp"
#include "Renderable.hpp"
#include "Cube.hpp"
#include "Quaternion.hpp"

class AnimateScript : public Renderable {
public:
    AnimateScript();
    void update(float time) override;
private:
    std::shared_ptr<Cube> cube;
    Quaternion rspeed1;
    Quaternion rspeed2;
};

#endif