#include "Cube.hpp"

Cube::Cube() {
    init(0);
}

Cube::Cube(unsigned density) {
    init(density);
}

void Cube::init(unsigned density) {
    speed = Vector3(1.0f,1.0f,1.0f)/200.0f;
    makeVertices(density);
}

void Cube::makeVertices(unsigned density) {
    const float step = 2*S/(density+1);
    if (density > 1000)
        density = 1000;
    
    for (int i = 0; i <= density+1; i++) {
        vertices.push_back(Vector3{-S+i*step,-S,-S});
        vertices.push_back(Vector3{-S,-S+i*step,-S});
        vertices.push_back(Vector3{-S,-S,-S+i*step});
        vertices.push_back(Vector3{ S-i*step, S, S});
        vertices.push_back(Vector3{ S, S-i*step, S});
        vertices.push_back(Vector3{ S, S, S-i*step});
    }
    for (int i = 1; i <= density; i++) {
        vertices.push_back(Vector3{ S,-S+i*step,-S});
        vertices.push_back(Vector3{ S,-S,-S+i*step});
        vertices.push_back(Vector3{-S+i*step, S,-S});
        vertices.push_back(Vector3{-S, S,-S+i*step});
        vertices.push_back(Vector3{-S+i*step,-S, S});
        vertices.push_back(Vector3{-S,-S+i*step, S});
    }
}

void Cube::translate(const Vector3& v) {
    for (Vector3& vertex : vertices) 
        vertex += v;
}

void Cube::translate(float x, float y, float z) {
    for (Vector3& v : vertices) {
        v.x += x;
        v.y += y;
        v.z += z;
    }
}

void Cube::scale(float c) {
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i] = vertices[i]*c;
    }
}

void Cube::scale(float x, float y, float z) {
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i].x = vertices[i].x*x;
        vertices[i].y = vertices[i].y*y;
        vertices[i].z = vertices[i].z*z;
    }
}

void Cube::update(float time) {
    translate(speed);
    scale(0.995f);
}
