#ifndef genesis_event_dispatcher
#define genesis_event_dispatcher

#include <functional>
#include <map>
#include <string>
#include <vector>

namespace Genesis {

/**
 * @file event_dispatcher.hpp
 * @brief EventDispatcher is responsible for managing event listeners and
 * dispatching events.
 *
 * @note The implementation assumes a basic event system where events are
 * identified by strings.
 * @note This code uses C++ standard library components such as std::function,
 * std::map, and std::vector.
 *
 * @class EventDispatcher
 */
class EventDispatcher {
   public:
    /**
     * @brief Type alias for the event listener function.
     */
    using EventListener = std::function<void()>;

    /**
     * @brief Adds an event listener for the specified event type.
     * @param eventType The type of event to listen for.
     * @param listener The listener function to call when the event occurs.
     */
    void addEventListener(const std::string& eventType,
                          const EventListener& listener);

    /**
     * @brief Removes an event listener for the specified event type.
     * @param eventType The type of event to stop listening for.
     * @param listener The listener function to remove.
     */
    void removeEventListener(const std::string& eventType,
                             const EventListener& listener);

    /**
     * @brief Dispatches an event of the specified type, calling all registered
     * listeners.
     * @param eventType The type of event to dispatch.
     */
    void dispatchEvent(const std::string& eventType);

   private:
    /**
     * @brief A map from event types to a list of event listeners.
     */
    std::map<std::string, std::vector<EventListener>> _listeners;
};

}  // namespace Genesis

#endif  // genesis_event_dispatcher
