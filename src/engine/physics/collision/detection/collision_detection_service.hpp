#ifndef genesis_collision_detection_service
#define genesis_collision_detection_service

#include "core/service.hpp"

namespace Genesis {

class Application;  // Forward declaration

/**
 * @brief Service responsible for detecting collisions between objects.
 *
 * Credits: https://winter.dev/articles/physics-engine, and ChatGPT.
 */
class CollisionDetectionService : public Service {
   public:
    /**
     * Initializes the Service.
     *
     * @param genesis Pointer to the main application engine.
     */
    void initialize(App* genesis);

    /**
     * @brief Check for collisions.
     *
     * It is called "every" frame to check for collisions between objects.
     * It processes the current state of the objects and detects any collisions,
     * handling them accordingly.
     */
    void update();

    /**
     * @brief Terminates the Collision Detection Service.
     *
     * This method cleans up any resources or data structures used by the
     * collision detection system. It is called when the service is no longer
     * needed.
     */
    void terminate();

   private:
    /**
     * @brief Flag to track pending objects.
     */
    bool objectsPending = false;
};

}  // namespace Genesis

#endif  // genesis_collision_detection_service
