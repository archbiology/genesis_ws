#include "event_service.hpp"

// #include "app.hpp"

namespace Genesis {

void EventService::update(App &engine) {
    do {
        eventsPending = false;
        engine.updateObjects();
    } while (eventsPending);
}

}  // namespace Genesis
