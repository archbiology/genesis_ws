#include "event_service.hpp"

// #include "app.hpp"

namespace Genesis {

// void EventService::initialize(const std::string& param)() {

// }

// void EventService::update(Application &engine) {
void EventService::update() {
    do {
        eventsPending = false;
        // engine.updateObjects();
    } while (eventsPending);
}

void EventService::terminate() {}
}  // namespace Genesis
