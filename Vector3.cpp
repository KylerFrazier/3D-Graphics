#include <stdexcept>
#include <sstream>
#include "Vector3.hpp"

Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f) {}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3::Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}

float& Vector3::operator[](int i) {
    switch (i) {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        default: throw std::out_of_range("Index error. Vector3 index out of range. Index " + std::to_string(i) + " not in range [0,2].");
    }
}

Vector3 Vector3::operator+(const Vector3& v) const {
    return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3& Vector3::operator+=(const Vector3& v) {
    x += v.x; y += v.y; z += v.z;
    return *this;
}

Vector3 Vector3::operator*(const float& c) const {
    return Vector3(c*x, c*y, c*z);
}

Vector3 operator*(float const& c, Vector3 const& v) {
    return v*c;
}

Vector3& Vector3::operator*=(const float& c) {
    x *= c; y *= c; z *= c; 
    return *this;
}

Vector3 Vector3::operator/(const float& c) const {
    return Vector3(x/c, y/c, z/c);
}

Vector3& Vector3::operator/=(const float& c) {
    x /= c; y /= c; z /= c; 
    return *this;
}

std::string Vector3::toString() const {
    std::ostringstream oss;
    oss << "Vector3(" << x << ", " << y << ", " << z << ")";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Vector3& v) {
    os << v.toString();
    return os;
}
