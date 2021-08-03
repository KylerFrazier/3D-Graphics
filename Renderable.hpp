#ifndef __RENDERABLE_H
#define __RENDERABLE_H

#include <vector>
#include "Vector3.hpp"

class Renderable {
public:
    virtual void render() const;
    virtual void update(float time) {}; 
protected:
    std::vector<Vector3> vertices;
};

#endif