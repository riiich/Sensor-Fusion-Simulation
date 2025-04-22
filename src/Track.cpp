#include "Track.h"
#include <cmath>

Track::Track(TrackID id, const Detection& initialDetection) :
    id_(id), 
    estimatedPosition_(initialDetection.measuredPosition), 
    estimatedVelocity_(0, 0, 0),
    lastUpdateTime_(initialDetection.timestamp)
{}

Track::TrackID Track::getID() const {
    return id_;
}

Vector3D Track::getPosition() const {
    return estimatedPosition_;
}

Vector3D Track::getVelocity() const {
    return estimatedVelocity_;
}

double Track::getLastUpdateTime() const {
    return lastUpdateTime_;
}

void Track::predict(double currTime) {
    double deltaTime = currTime - lastUpdateTime_;

    // predict future time
    if (deltaTime > 1e-9) {
        estimatedPosition_ = estimatedPosition_ + estimatedVelocity_ * deltaTime;
    }
}

void Track::update(const Detection& detection) {
    double deltaTime = detection.timestamp - lastUpdateTime_;

    if (deltaTime > 1e-6) {
        estimatedPosition_ = (detection.measuredPosition - estimatedPosition_) * (1.0 / deltaTime);
    }

    // a real system would use filtering (kalman, ...)
    estimatedPosition_ = detection.measuredPosition;
    lastUpdateTime_ = detection.timestamp;
}