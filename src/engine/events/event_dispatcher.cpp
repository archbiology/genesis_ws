#include "event_dispatcher.hpp"

#include <algorithm>

namespace Genesis {

void EventDispatcher::addEventListener(const std::string& eventType,
                                       const EventListener& listener) {
    _listeners[eventType].push_back(listener);
}

void EventDispatcher::removeEventListener(const std::string& eventType,
                                          const EventListener& listener) {
    auto& listeners = _listeners[eventType];
    listeners.erase(std::remove(listeners.begin(), listeners.end(), listener),
                    listeners.end());
}

void EventDispatcher::dispatchEvent(const std::string& eventType) {
    auto it = _listeners.find(eventType);
    if (it != _listeners.end()) {
        for (const auto& listener : it->second) {
            listener();
        }
    }
}

}  // namespace Genesis
