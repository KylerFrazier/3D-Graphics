#ifndef __VECTOR3_H
#define __VECTOR3_H

#include <iostream>
#include <string>

class Vector3 {
public:
    float x;
    float y;
    float z;
    Vector3();
    Vector3(float x, float y, float z);
    Vector3(Vector3 const& v);
    float& operator[](int i) ;
    Vector3 operator+(Vector3 const& v) const;
    Vector3& operator+=(Vector3 const& v);
    Vector3 operator-(Vector3 const& v) const;
    Vector3& operator-=(Vector3 const& v);
    Vector3 operator*(float const& c) const;
    Vector3& operator*=(float const& c);
    Vector3 operator/(const float& c) const;
    Vector3& operator/=(const float& c);
    std::string toString() const;
};

Vector3 operator*(float const& c, Vector3 const& v);
std::ostream& operator<<(std::ostream& os, const Vector3& dt);

#endif