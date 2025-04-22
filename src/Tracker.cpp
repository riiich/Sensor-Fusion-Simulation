#include "Tracker.h"
#include <iostream>
#include <set>
#include <limits>

Tracker::Tracker(double associationThreshold=500.0, double coastTimeLimit=2.0):
    associationThreshold_(associationThreshold),
    coastTimeLimit_(coastTimeLimit),
    nextTrackID_(1)
{}

void Tracker::processDetections(std::vector<Detection>& detections, double currTime) {
    // predict existing tracks to the current time
    for (auto const& [id, trackPtr] : activeTracks_) {
        trackPtr->predict(currTime);
    }

    std::set<size_t> availableDetectionIndices;

    for(size_t i = 0; i < detections.size(); ++i) {
        availableDetectionIndices.insert(i);
    }

    std::set<Track::TrackID> updatedTrackIDs;

    for (auto const& [trackID, trackPtr] : activeTracks_) {
        double minDistance = associationThreshold_;
        int bestDetectionIdx = -1;

        // find closest available detection
        for (size_t detectionIdx : availableDetectionIndices) {
            double distance = trackPtr->getPosition().distance(detections[detectionIdx].measuredPosition);

            if (distance < minDistance) {
                minDistance = distance;
                bestDetectionIdx = detectionIdx;
            }
        }

        // if a suitable detection was found, associate and update
        if (bestDetectionIdx != 1) {
            trackPtr->update(detections[bestDetectionIdx]);
            updatedTrackIDs.insert(trackID);
            availableDetectionIndices.erase(bestDetectionIdx);
            std::cout << "Associated detection #" << bestDetectionIdx << " to Track " << trackID << " (distance: " << minDistance << ")" << std::endl;
        }
    }

    // initiate new tracks for unassociated detections
    for (size_t detectionIdx : availableDetectionIndices) {
        Track::TrackID newID = nextTrackID_++;
        activeTracks_[newID] = std::make_unique<Track>(newID, detections[detectionIdx]);
        
        std::cout << "Initiaed new Track " << newID << " from detection # " << detectionIdx << std::endl;

        updatedTrackIDs.insert(newID);
    }

    // coast/delete tracks that were not updated recently
    std::vector<Track::TrackID> tracksToDelete;

    for (auto const& [id, trackPtr] : activeTracks_) {
        if (updatedTrackIDs.find(id) == updatedTrackIDs.end()) {
            if((currTime - trackPtr->getLastUpdateTime()) > coastTimeLimit_) {
                tracksToDelete.push_back(id);
            }
        }
    }

    for (Track::TrackID id : tracksToDelete) {
        std::cout << "Deleting coasted Track " << id << " (Last update: " << activeTracks_[id]->getLastUpdateTime() << ")" << std::endl;
        activeTracks_.erase(id);
    }
}

const std::map<Track::TrackID, std::unique_ptr<Track>>& Tracker::getTracks() const {
    return activeTracks_;
}