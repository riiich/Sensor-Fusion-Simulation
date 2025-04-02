#pragma once

#include "Vector3D.h"
#include <cstdint>  // uint64_t
#include <string>

// Target represents an object that is being tracked
class Target {
    public:
        using TargetID = uint64_t;

        Target(TargetID id, const Vector3D& initialPosition, const Vector3D& initialVelocity);

        TargetID getID() const;
        Vector3D getPosition() const;
        Vector3D getVelocity() const;
        std::string getType() const;    // ex. "Aircraft", "Missile", ...

        void updateTargetState(double deltaTimeSeconds);
    
    private:
        TargetID id_;
        Vector3D position_;
        Vector3D velocity_;
        std::string type_;
};
