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
    src/engine/core/app.cpp
    src/engine/core/creation.cpp
    src/engine/core/component.cpp
    src/engine/events/event_service.cpp
    src/engine/main.cpp
)
