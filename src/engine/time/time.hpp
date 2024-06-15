#ifndef genesis_time
#define genesis_time

#include <chrono>

namespace Genesis {

/**
 * @brief The Time class provides functionality for managing time in the
 * application.
 */
class Time {
   public:
    /**
     * @brief Constructs the Time instance.
     *
     * Throws an exception if an instance already exists.
     */
    Time();

    /**
     * @brief Initializes the Time instance.
     *
     * Initializes the current time using high-resolution clock.
     */
    void initialize();

    /**
     * @brief Updates the current time.
     *
     * Updates the current time using high-resolution clock.
     */
    void update();

    /**
     * @brief Static instance of Time class.
     *
     * Provides access to the singleton instance of Time.
     */
    static Time* instance;

   private:
    /**
     * @brief Current time point using high-resolution clock.
     */
    std::chrono::time_point<std::chrono::high_resolution_clock> currentTime;
};

}  // namespace Genesis

#endif  // genesis_time
