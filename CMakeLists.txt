cmake_minimum_required(VERSION 3.10)

# --------------------
# Set the project name
# --------------------
project(Genesis)

include_directories(src/engine)

# --------------------
# Set the C++ standard
# --------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ------------------
# Add the executable
# ------------------
add_executable(
    genesis
    src/engine/main.cpp
    src/engine/core/app.cpp
    src/engine/math/vec3.cpp
    src/engine/core/creation.cpp
    src/engine/core/component.cpp
    src/engine/events/event_service.cpp
    src/engine/physics/dynamics/dynamics_service.cpp
    src/engine/physics/collision/detection/collision_checker.cpp
    src/engine/physics/collision/detection/collision_detection_service.cpp
)
