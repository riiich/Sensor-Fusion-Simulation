#pragma once 

#include <cmath>
#include <iostream>

// Vector3D is used to determine the location of an object in 3D space
struct Vector3D {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    // constructors
    Vector3D() = default;
    Vector3D(double x, double y, double z);

    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    Vector3D operator*(double scalar) const;    

    Vector3D normalize() const;
    double magnitude() const;

    // friend function to print vector
    friend std::ostream& operator <<(std::ostream& os, const Vector3D& vec);
};

Vector3D operator*(double scalar, const Vector3D& vec);