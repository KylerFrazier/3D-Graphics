#ifndef __QUATERNION_H
#define __QUATERNION_H

#include "Vector3.hpp"

class Quaternion {
public:
    Quaternion();
    Quaternion(float theta, Vector3 axis);
    Quaternion(float theta, float x, float y, float z);
    Vector3 operator*(const Vector3& v) const;
    void normalize();
private:
    float w;
    Vector3 v;
    float mat[4][4];
    void makeMatrix();
};

#endif