#ifndef genesis_event_service
#define genesis_event_service

#include "core/service.hpp"

namespace Genesis {

class Application;  // Forward declaration


/**
 * @brief The EventService.
 *
 * @details Manages event handling within the application.
 * Inherits from Service.
 */
class EventService : public Service {
   public:

   /**
     * Initializes the Service.
     *
     * @param param Optional parameters for initialization.
     */
    void initialize(App* genesis);

    /**
     * Terminates the Service.
     */
    void terminate();

    /**
     * Updates the Service.
     */
    void update();

    /**
     * @brief Updates the EventService.
     *
     * @details Continuously updates objects in the application
     * until no events are pending.
     */
    // void update(Application &application);

   private:
    /**
     * @brief Flag to track pending events.
     */
    bool eventsPending = false;
};

}  // namespace Genesis

#endif  // genesis_event_service
