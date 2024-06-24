#ifndef genesis_collision_response
#define genesis_collision_response

#include "core/service.hpp"

namespace Genesis {

/**
 * @brief The class manages collision responses in the simulation.
 *
 * This class is responsible responding to collisions between objects to ensure
 * realistic physics behavior.
 *
 * Credits: https://winter.dev/articles/physics-engine, and ChatGPT.
 */
class CollisionResponseService : public Service {
   public:
    /**
     * Initializes the Service.
     *
     * @param param Optional parameters for initialization.
     */
    void initialize(App* genesis) override;

    /**
     * @brief Updates the CollisionResponseService.
     *
     * This method is called periodically to update collision responses.
     * It applies appropriate responses to affected objects.
     */
    void update() override;

    /**
     * Terminates the Service.
     */
    void terminate() override;

   private:
    /**
     * @brief Flag to track pending objects.
     */
    bool objectsPending = false;
};

}  // namespace Genesis

#endif  // genesis_collision_response
