# CMakeLists.txt
cmake_minimum_required(VERSION 3.15) # Use a reasonably modern version
project(SensorFusionSim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17) # Or 20
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Good practice

# Tell CMake where to find header files
include_directories(include)

# Add your executable target
add_executable(sim_app src/main.cpp
                        src/Vector3D.cpp
                        src/Target.cpp
                        src/Sensor.cpp
                        src/RadarSensor.cpp
                        src/Track.cpp
                        src/Tracker.cpp
                      )

# Optional: Improve build output location (especially for multi-config generators like VS)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Optional: Enable warnings (highly recommended)
if(MSVC)
    add_compile_options(/W4 /WX) # Treat warnings as errors on MSVC
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror) # Treat warnings as errors on GCC/Clang
endif()