#pragma once

#include <vector>
#include <memory>
#include <random>
#include <mutex>
#include "Vector3D.h"
#include "Target.h"
#include "Detection.h"

// base class for different sensors
class Sensor {
    public:
        Sensor(const Vector3D& position, double range);
        virtual ~Sensor() = default;

        virtual std::vector<Detection> detect(const std::vector<std::unique_ptr<Target>>& potentialTarget, double currTime) const = 0;

        Vector3D getPosition() const;
        double getRange() const;

    protected:  // using protected so that derived classes can access
        Vector3D position_;
        double detectionRange_;
        mutable std::mt19937 random_engine_;
        mutable std::normal_distribution<double> noise_distribution_;

        // noise is the random errors or inaccuracies in the sensor measurements
        Vector3D addNoise(const Vector3D& truePosition, double noiseStdDev) const;
};
