#include "RadarSensor.h"
#include <vector>

RadarSensor::RadarSensor(const Vector3D& position, double range, double noiseStdDev):
    Sensor(position, range),
    noiseStdDev_(noiseStdDev)
{}

std::vector<Detection> RadarSensor::detect(const std::vector<std::unique_ptr<Target>>& potentialTargets, double currTime) const{
    std::vector<Detection> detections;

    for (const auto& targetPtr : potentialTargets) {
        double distanceToTarget = position_.distance(targetPtr->getPosition());
        
        if (distanceToTarget <= detectionRange_) {
            Detection detection;

            detection.measuredPosition = addNoise(targetPtr->getPosition(), noiseStdDev_);
            detection.timestamp = currTime;
            detections.push_back(detection);
        }
    }

    return detections;
}
