#include "Quaternion.hpp"
#include <cmath>
#include <iostream>

Quaternion::Quaternion() : Quaternion(1, Vector3()) {}

Quaternion::Quaternion(float theta, Vector3 axis) 
: w(std::cos(theta/2)), v(std::sin(theta/2)*axis) {
    makeMatrix();
}

Quaternion::Quaternion(float theta, float x, float y, float z)
: Quaternion(theta, Vector3(x, y, z)) {}

Vector3 Quaternion::operator*(const Vector3& vector) const {
    float vec[4] = {vector.x, vector.y, vector.z, 1};
    float dot[4] = {0};
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            dot[i] += mat[i][j] * vec[j];
    if (dot[3] != 1)
        std::cout << "DOT PRODUCT DID WHAT??? NANIIIII???... " << dot[3] << std::endl;
    return Vector3(dot[0], dot[1], dot[2]);
}

void Quaternion::normalize() {
    float norm = std::sqrt(pow(w,2) + pow(v[0],2) + pow(v[1],2) + pow(v[2],2));
    w /= norm;
    v /= norm;
}

void Quaternion::makeMatrix() {
    normalize();
    float x = v[0], y = v[1], z = v[2];
    
    mat[0][0] = 1 - 2*pow(y,2) - 2*pow(z,2);
    mat[0][1] = 2*x*y - 2*w*z;
    mat[0][2] = 2*x*z + 2*w*y;
    mat[0][3] = 0;

    mat[1][0] = 2*x*y + 2*w*z;
    mat[1][1] = 1 - 2*pow(x,2) - 2*pow(z,2);
    mat[1][2] = 2*y*z + 2*w*x;
    mat[1][3] = 0;

    mat[2][0] = 2*x*z - 2*w*y;
    mat[2][1] = 2*y*z - 2*w*x;
    mat[2][2] = 1 - 2*pow(x,2) - 2*pow(y,2);
    mat[2][3] = 0;

    mat[3][0] = 0;
    mat[3][1] = 0;
    mat[3][2] = 0;
    mat[3][3] = 1;
}