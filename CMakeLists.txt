cmake_minimum_required(VERSION 3.10)

# --------------------
# Set the project name
# --------------------
project(Genesis)

# --------------------
# Set the C++ standard
# --------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ------------------
# Add the executable
# ------------------
add_executable(genesis src/engine/core/creation.cpp src/engine/main.cpp)