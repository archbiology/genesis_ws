#include "event_service.hpp"

// #include "app.hpp"

namespace Genesis {

void EventService::initialize(App* genesis) { this->genesis = genesis; }

// void EventService::update(Application &engine) {
void EventService::update() {
    do {
        eventsPending = false;
        // engine.updateObjects();
    } while (eventsPending);
}

void EventService::terminate() {}
}  // namespace Genesis
