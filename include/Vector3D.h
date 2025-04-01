#pragma once 

#include <cmath>
#include <iostream>

struct Vector3D {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    Vector3D() = default;
    Vector3D(double x, double y, double z);

    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    Vector3D operator*(double scalar) const;    

    double magnitude() const;
    Vector3D normalize() const;

    friend std::ostream& operator <<(std::ostream& os, const Vector3D& vector);
};

Vector3D operator*(double scalar, const Vector3D& vector);