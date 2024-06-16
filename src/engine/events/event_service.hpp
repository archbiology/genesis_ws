#ifndef genesis_event_service
#define genesis_event_service

#include "core/service.hpp"

namespace Genesis {

class App;  // Forward declaration


/**
 * @brief The EventService.
 *
 * @details Manages event handling within the application.
 * Inherits from Service.
 */
class EventService : public Service {
   public:
    /**
     * @brief Updates the EventService.
     *
     * @details Continuously updates objects in the application
     * until no events are pending.
     */
    void update(App &application);

   private:
    /**
     * @brief Flag to track pending events.
     */
    bool eventsPending = false;
};

}  // namespace Genesis

#endif  // genesis_event_service
