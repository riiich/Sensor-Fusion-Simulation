#include "Vector3D.h"
#include <stdexcept>

Vector3D::Vector3D(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(this->x + other.x, this->y + other.y, this->z + other.z);   
}

Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vector3D Vector3D::operator*(double scalar) const {
    return Vector3D(this->x * scalar, this->y * scalar, this->z * scalar);
}

Vector3D Vector3D::normalize() const {
    double magnitude = this->magnitude();

    if (magnitude <= 0.0) 
        throw std::runtime_error("This vector cannot be normalized! Take a look at the vector.");

    return Vector3D(this->x / magnitude, this->y / magnitude, this->z / magnitude);
}

double Vector3D::magnitude() const {
    return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

std::ostream& operator<<(std::ostream& os, const Vector3D& vec) {
    os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";

    return os;
}

Vector3D operator*(double scalar, const Vector3D& vec) {
    return scalar * vec;     // using the member operator
}




// Vector3D x = new Vector3D(1,2,3);    [1,2,3]
// Vector3D y = new Vector3D(4,5,6);    [4,5,6]

// Vector3D z = x + y; [5,7,9]