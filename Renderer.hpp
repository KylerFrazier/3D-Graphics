#ifndef __RENDERER_H
#define __RENDERER_H

#include <memory>
#include <vector>
#include "Renderable.hpp"

namespace renderer {
    extern const float DELTA_TIME; 
    extern std::vector<std::shared_ptr<Renderable>> renderables;
    void init(int* argc, char* argv[]);
    void display();
    void update(int);
    void addRenderable(std::shared_ptr<Renderable> r);
}

#endif