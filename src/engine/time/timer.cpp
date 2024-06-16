#include "timer.hpp"

#include "time.hpp"

namespace Genesis {

Timer::Timer(const bool& loop, const int duration)
    : currentTime(Time::instance->currentTime),
      running(false),
      duration(duration),
      loop(loop),
      lastFraction(0) {}

void Timer::update() {
    if (!running) return;

    std::chrono::time_point<std::chrono::high_resolution_clock> now =
        Time::instance->currentTime;
    // double deltat = now - currentTime;
    std::chrono::duration<double, std::milli> deltat = now - currentTime;

    // Convert to double
    double delta_milliseconds = deltat.count();

    if (delta_milliseconds > 0) {
        // dispatchEvent("time", now);
        dispatchEvent("time");
    }

    if (duration > 0) {
        // FIXME: Use int directly instead of converting double to int.
        // double mod = now % duration;
        double mod = int(delta_milliseconds) % int(duration);
        double fract = mod / duration;

        // dispatchEvent("fraction", fract);
        dispatchEvent("fraction");

        if (fract < lastFraction) {
            dispatchEvent("cycleTime");

            if (!loop) {
                stop();
            }
        }

        lastFraction = fract;
    }

    currentTime = now;
}

void Timer::start() {
    running = true;
    currentTime = Time::instance->currentTime;
}

void Timer::stop() { running = false; }

}  // namespace Genesis
