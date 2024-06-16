#ifndef genesis_app
#define genesis_app

#include <memory>
#include <vector>

#include "creation.hpp"
#include "service.hpp"

namespace Genesis {

class EventDispatcher;
class Time;
class Input;
class Services;

/**
 * The base Application class.
 */
class Application {
   public:
    /**
     * Constructor.
     */
    Application(const std::string& param = "");

    /**
     * Destructor.
     */
    ~Application();

    /**
     * Initializes the Application.
     */
    void initialize(const std::string& param = "");

    /**
     * Adds a service to the application.
     * @param serviceName The name of the service to add.
     */
    void addService(const std::string& serviceName);

    /**
     * Initializes all added services.
     */
    void initServices(const std::string& param = "");

    /**
     * Focuses the application.
     */
    void focus();

    /**
     * Starts running the application.
     */
    void run();

    /**
     * Main application loop.
     */
    void runloop();

    /**
     * Updates all services.
     */
    void updateServices();

    /**
     * Updates all objects.
     */
    void updateObjects();

    /**
     * Adds an object to the application.
     * @param o The object to add.
     */
    void addObject(std::shared_ptr<Genesis::Creation> o);

    /**
     * Removes an object from the application.
     * @param o The object to remove.
     */
    void removeObject(std::shared_ptr<Genesis::Creation> o);

    /**
     * Realizes all objects.
     */
    void realizeObjects();

    /**
     * Event handler for mouse move.
     * @param event The mouse move event.
     */
    // void onMouseMove(const MouseEvent& event);

    /**
     * Event handler for mouse down.
     * @param event The mouse down event.
     */
    // void onMouseDown(const MouseEvent& event);

    /**
     * Event handler for mouse up.
     * @param event The mouse up event.
     */
    // void onMouseUp(const MouseEvent& event);

    /**
     * Event handler for mouse click.
     * @param event The mouse click event.
     */
    // void onMouseClick(const MouseEvent& event);

    /**
     * Event handler for mouse double click.
     * @param event The mouse double click event.
     */
    // void onMouseDoubleClick(const MouseEvent& event);

    /**
     * Event handler for mouse scroll.
     * @param event The mouse scroll event.
     */
    // void onMouseScroll(const MouseScrollEvent& event);

    /**
     * Event handler for key down.
     * @param event The key down event.
     */
    // void onKeyDown(const KeyEvent& event);

    /**
     * Event handler for key up.
     * @param event The key up event.
     */
    // void onKeyUp(const KeyEvent& event);

    /**
     * Event handler for key press.
     * @param event The key press event.
     */
    // void onKeyPress(const KeyEvent& event);

    /**
     * Static method to handle mouse move events.
     * @param event The mouse move event.
     */
    // static void handleMouseMove(const MouseEvent& event);

    /**
     * Static method to handle mouse down events.
     * @param event The mouse down event.
     */
    // static void handleMouseDown(const MouseEvent& event);

    /**
     * Static method to handle mouse up events.
     * @param event The mouse up event.
     */
    // static void handleMouseUp(const MouseEvent& event);

    /**
     * Static method to handle mouse click events.
     * @param event The mouse click event.
     */
    // static void handleMouseClick(const MouseEvent& event);

    /**
     * Static method to handle mouse double click events.
     * @param event The mouse double click event.
     */
    // static void handleMouseDoubleClick(const MouseEvent& event);

    /**
     * Static method to handle mouse scroll events.
     * @param event The mouse scroll event.
     */
    // static void handleMouseScroll(const MouseScrollEvent& event);

    /**
     * Static method to handle key down events.
     * @param event The key down event.
     */
    // static void handleKeyDown(const KeyEvent& event);

    /**
     * Static method to handle key up events.
     * @param event The key up event.
     */
    // static void handleKeyUp(const KeyEvent& event);

    /**
     * Static method to handle key press events.
     * @param event The key press event.
     */
    // static void handleKeyPress(const KeyEvent& event);

   private:
    bool running;
    bool tabstop;
    std::vector<std::shared_ptr<Service>> _services;
    std::vector<std::shared_ptr<Creation>> _objects;
    Time* _time;                 // Example instance of Time
    Input* _input;               // Example instance of Input
    Services* _servicesManager;  // Example instance of Services

    std::shared_ptr<Service> createService(const std::string& serviceName);
};

}  // namespace Genesis

#endif  // genesis_app
