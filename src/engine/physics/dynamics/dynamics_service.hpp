#ifndef genesis_dynamics_service
#define genesis_dynamics_service

#include "core/heart.hpp"
#include "core/service.hpp"
#include "math/vec3.hpp"

namespace Genesis {

class App;  // Forward declaration

/**
 * @brief The DynamicsService.
 *
 * @details Dynamics is all about calculating where the new positions
 * of objects are based on their velocity and acceleration.
 *
 * Credits: https://winter.dev/articles/physics-engine#Dynamics
 */
class DynamicsService : public Service {
    Vec3 gravity = Vec3(0, -9.81f, 0);

   public:
    /**
     * Initializes the Service.
     *
     * @param genesis The engine address.
     */
    void initialize(App* genesis);

    /**
     * @brief Updates the DynamicsService.
     * @details Updates objects position in the application.
     */
    void update();

    /**
     * Terminates the Service.
     */
    void terminate();

   private:
    /**
     * @brief Flag to track pending objects.
     */
    bool objectsPending = false;
};

}  // namespace Genesis

#endif  // genesis_dynamics_service
