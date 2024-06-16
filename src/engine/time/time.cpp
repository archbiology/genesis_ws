#include "time.hpp"

#include <stdexcept>  // For std::runtime_error

namespace Genesis {

// Initialize static instance
Time* Time::instance = nullptr;

Time::Time() {
    // Freak out if somebody tries to make 2
    if (Time::instance) {
        throw std::runtime_error("Time singleton already exists");
    }

    Time::instance = this;
}

void Time::initialize() {
    currentTime = std::chrono::high_resolution_clock::now();
}

void Time::update() { currentTime = std::chrono::high_resolution_clock::now(); }

}  // namespace Genesis
