#include "Cube.hpp"

Cube::Cube() { makeVertices(0); }

Cube::Cube(unsigned density) { makeVertices(density); }

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
    translation += v;
    for (Vector3& vertex : vertices) 
        vertex += v;
}

void Cube::translate(float x, float y, float z) {
    translate(Vector3(x, y, z));
}

void Cube::rotate(const Quaternion& q) {
    translation = q * translation;
    for (int i = 0; i < vertices.size(); i++)
        vertices[i] = q * vertices[i];
}

void Cube::localRotate(const Quaternion& q) {
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i] = translation + q * (vertices[i] - translation);
    }
}

void Cube::scale(float c) {
    for (int i = 0; i < vertices.size(); i++)
        vertices[i] = translation + c * (vertices[i] - translation);
}

void Cube::scale(float x, float y, float z) {
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i].x = translation.x + x * (vertices[i].x - translation.x);
        vertices[i].y = translation.y + y * (vertices[i].y - translation.y);
        vertices[i].z = translation.z + z * (vertices[i].z - translation.z);
    }
}
