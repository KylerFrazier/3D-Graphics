#ifndef __CUBE_H
#define __CUBE_H

#include <vector>
#include "Renderable.hpp"
#include "Quaternion.hpp"

class Cube : public Renderable {
public:
    Cube();
    Cube(unsigned density);
    void translate(const Vector3& v);
    void translate(float x, float y, float z);
    void rotate(const Quaternion& q);
    void localRotate(const Quaternion& q);
    void scale(float c);
    void scale(float x, float y, float z);
private:
    static constexpr float S = 0.5f;

    Vector3 translation;
    
    void makeVertices(unsigned density);
};

#endif