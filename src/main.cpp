#include <iostream>
#include <vector>
#include <memory>
#include <chrono>
#include <thread>
#include <future>
#include <functional>
#include "Vector3D.h"
#include "Target.h"
#include "Detection.h"
#include "Tracker.h"
#include "RadarSensor.h"

int main() {
    std::cout << "---------------- SIMULATION START ----------------" << std::endl;

    double simulationTime = 0.0;
    double deltaTime = 0.1;     // seconds
    double endTime = 10.0;      // seconds
    
    // targets
    std::vector<std::unique_ptr<Target>> targets;
    targets.push_back(std::make_unique<Target>(1, Vector3D(1000, 2000, 5000), Vector3D(50, -20, 1)));
    targets.push_back(std::make_unique<Target>(2, Vector3D(-3000, 1500, 4000), Vector3D(-30, -15, 10)));
    targets.push_back(std::make_unique<Target>(3, Vector3D(0, 0, 6000), Vector3D(0, 0, -50)));    

    // sensors
    std::vector<std::unique_ptr<Sensor>> sensors;
    sensors.push_back(std::make_unique<RadarSensor>(Vector3D(0, 0, 0), 8000, 50.0));
    sensors.push_back(std::make_unique<RadarSensor>(Vector3D(5000, 0, 0), 6000, 75.0));
    sensors.push_back(std::make_unique<RadarSensor>(Vector3D(-5000, 0, 0), 7000, 60.0));
    sensors.push_back(std::make_unique<RadarSensor>(Vector3D(3000, 0, 0), 6500, 55.0));

    // tracker
    Tracker tracker(750.0, 1.5);

    // simulation
    while (simulationTime <= endTime) {
        auto loopStartTime = std::chrono::high_resolution_clock::now();

        std::cout << "Time: " << simulationTime << "s" << std::endl;
        std::cout << "Target updates: " << std::endl;

        // parallelize target updates
        // std::vector<std::thread> targetUpdateThreads;
        // targetUpdateThreads.reserve(targets.size());
        
        // for(auto& targetPtr : targets) {
        //     targetUpdateThreads.emplace_back(&T)
        // }

        for(const auto& targetPtr : targets) {
            targetPtr->updateTargetState(deltaTime);
            std::cout << "Target ID: " << targetPtr->getID() << " Position: " << targetPtr->getPosition() << std::endl;
        }

        
    }

    return 0;
}