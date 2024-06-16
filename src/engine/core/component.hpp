#ifndef genesis_component
#define genesis_component

#include "core/creation.hpp"
#include "events/event_dispatcher.hpp"

namespace Genesis {

/**
 * @file component.hpp
 * @brief Component is the base class for defining capabilities used within a
 * Creation
 *
 * @author Tony Parisi
 */

class Component : public EventDispatcher {
   public:
    /**
     * @brief Creates a new Component.
     */
    Component();

    /**
     * @brief Gets the Creation the Component is associated with.
     * @return The Creation the Component is associated with.
     */
    // Creation* getCreation() const;
    std::shared_ptr<Creation> getCreation() const;

    /**
     * @brief Sets the Creation the Component is associated with.
     * @param creation The Creation to associate with the Component.
     */
    // void setCreation(Creation* creation);
    void setCreation(std::shared_ptr<Creation> creation);

    /**
     * @brief Realizes the Component.
     */
    virtual void realize();

    /**
     * @brief Updates the Component.
     */
    virtual void update();

    /**
     * @brief The Creation the Component is associated with.
     */
    std::shared_ptr<Creation> _creation;

   private:
    /**
     * @brief Indicates whether the Component is realized.
     */
    bool _realized;
};

}  // namespace Genesis

#endif  // genesis_component
