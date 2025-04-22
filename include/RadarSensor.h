#pragma once

#include "Sensor.h"

class RadarSensor : public Sensor {
    public: 
        RadarSensor(const Vector3D& position, double range, double noistStdDev);

        std::vector<Detection> detect(const std::vector<std::unique_ptr<Target>>& potentialTargets, double currTime) const override;

    private:
        double noiseStdDev_;
};
