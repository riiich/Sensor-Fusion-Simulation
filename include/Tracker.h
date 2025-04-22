#pragma once

#include "Track.h"
#include "Detection.h"
#include <vector>
#include <map>
#include <memory>


class Tracker: public Track {
    public: 
        Tracker(double associationThreshold=500.0, double coastTimeLimit=2.0);

        // process a batch of detections for the current time step
        void processDetections(std::vector<Detection>& detections, double currTime); 

        // read-only access to the current objects that have been tracked
        const std::map<Track::TrackID, std::unique_ptr<Track>>& getTracks() const;

    private:
        std::map<Track::TrackID, std::unique_ptr<Track>> activeTracks_;
        Track::TrackID nextTrackID_ = 1;
        double associationThreshold_;
        double coastTimeLimit_;     
};