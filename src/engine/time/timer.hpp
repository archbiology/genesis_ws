#ifndef genesis_timer
#define genesis_timer

#include <chrono>

#include "core/component.hpp"

namespace Genesis {

/**
 * @brief Timer component that generates time events.
 */
class Timer : public Component {
   public:
    /**
     * @brief Constructs a Timer instance.
     * @param param Optional parameters for timer configuration.
     */
    Timer(const bool& loop = false, const int duration = 0);

    /**
     * @brief Updates the timer.
     *
     * Checks if the timer is running and dispatches events based on elapsed
     * time and duration if specified.
     */
    void update() override;

    /**
     * @brief Starts the timer.
     */
    void start();

    /**
     * @brief Stops the timer.
     */
    void stop();

    /**
     * @brief Current time in high-resolution clock.
     */
    std::chrono::time_point<std::chrono::high_resolution_clock> currentTime;

   private:
    bool running;         ///< Flag indicating whether the timer is running.
    double duration;      ///< Duration of the timer in seconds.
    bool loop;            ///< Flag indicating whether the timer should loop.
    double lastFraction;  ///< Last fraction of time passed.
};

}  // namespace Genesis

#endif  // genesis_timer
