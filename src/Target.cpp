#include "Target.h"

static Target::TargetID nextID = 1;

Target::Target(Target::TargetID id, const Vector3D& initialPosition, const Vector3D& initialVelocity) {
    this->id_ = id;
    this->position_ = initialPosition;
    this->velocity_ = initialVelocity;
}

Target::TargetID Target::getID() const {
    return this->id_;
}

Vector3D Target::getPosition() const {
    return this->position_;
}

Vector3D Target::getVelocity() const {
    return this->velocity_;
}

std::string Target::getType() const {
    return this->type_;
}

void Target::updateTargetState(double deltaTimeSeconds) {
    this->position_ = this->position_ + this->velocity_ * deltaTimeSeconds;
}