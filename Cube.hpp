#ifndef __CUBE_H
#define __CUBE_H

#include <vector>
#include "Renderable.hpp"

class Cube : public Renderable {
public:
    Cube();
    Cube(unsigned density);
    void translate(const Vector3& v);
    void translate(float x, float y, float z);
    // void rotate(float x, float y, float z);
    void scale(float c);
    void scale(float x, float y, float z);
    // void localRotate(int direction, float radians);
    void update(float time) override;
private:
    static constexpr float S = 0.5f;
    Vector3 speed;
    void init(unsigned density);
    void makeVertices(unsigned density);
};

#endif