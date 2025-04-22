#include "Sensor.h"
#include <limits>   // defines the range of values that a variable of a specific data type can hold

Sensor::Sensor(const Vector3D& position, double range) :
    position_(position),
    detectionRange_(range),
    random_engine_(std::random_device{}()),
    noise_distribution_(0.0, 1.0)
{}

Vector3D Sensor::getPosition() const {
    return this->position_;
}

double Sensor::getRange() const {
    return this->detectionRange_;
}

Vector3D Sensor::addNoise(const Vector3D& truePosition, double noiseStdDev) const {
    // check if the standard deviation is positive
    if (noiseStdDev <= 0) {
        return truePosition;
    }

    return Vector3D(truePosition.x + noise_distribution_(random_engine_) * noiseStdDev,
                    truePosition.y + noise_distribution_(random_engine_) * noiseStdDev,
                    truePosition.z + noise_distribution_(random_engine_) * noiseStdDev
    );
}
