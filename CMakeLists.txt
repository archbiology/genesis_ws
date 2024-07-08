cmake_minimum_required(VERSION 3.10)

# --------------------
# Set the project name
# --------------------
project(Genesis)

include_directories(src/engine)

# --------------------------
# Locate Google Test package
# --------------------------
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# --------------------
# Set the C++ standard
# --------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# -------------------
# Define source files
# -------------------
set(GENESIS_CPP_FILES
    src/engine/core/app.cpp
    src/engine/math/vec3.cpp
    src/engine/core/creation.cpp
    src/engine/core/component.cpp
    src/engine/events/event_service.cpp
    src/engine/networking/websocket_server.cpp
    src/engine/networking/websocket_service.cpp
    src/engine/physics/dynamics/dynamics_service.cpp
    src/engine/physics/collision/response/impulse_solver.cpp
    src/engine/physics/collision/detection/collision_checker.cpp
    src/engine/physics/collision/response/collision_response_service.cpp
    src/engine/physics/collision/detection/collision_detection_service.cpp
)

# ---------------------
# Define the test files
# ---------------------
set(GENESIS_TEST_FILES
    src/engine/tests/physics/test_dynamics_service.cpp
)

# ----------------------------
# Add the `genesis` executable
# ----------------------------
add_executable(genesis src/engine/main.cpp ${GENESIS_CPP_FILES})
target_link_libraries(genesis websockets)


# ------------------------------
# Add the `unitTests` executable
# ------------------------------
add_executable(
    unitTests src/engine/tests/main.cpp
    ${GENESIS_CPP_FILES}
    ${GENESIS_TEST_FILES}
)
target_link_libraries(unitTests ${GTEST_LIBRARIES} pthread websockets)
