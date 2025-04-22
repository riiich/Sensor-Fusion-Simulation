#pragma once

#include <cstdint>
#include "Vector3D.h"
#include "Detection.h"

class Track {
    public:
        using TrackID = uint64_t;

        Track() = default;
        Track(TrackID id, const Detection& initialDetection);

        TrackID getID() const;
        Vector3D getPosition() const;
        Vector3D getVelocity() const;
        double getLastUpdateTime() const;

        void predict(double currTime);  // predict track state to the current time
        void update(const Detection& detection);    // update track state based on associated detection
        
    private:
        TrackID id_;
        Vector3D estimatedPosition_;
        Vector3D estimatedVelocity_;
        double lastUpdateTime_;
};
