#include "application.hpp"

#include "core/service.hpp"
#include "events/event_service.hpp"
#include <iostream>

namespace Genesis {

Application::Application(const std::string& param)
    : running(false),
      tabstop(false),
      _time(nullptr),
      _input(nullptr),
      _servicesManager(nullptr) {
    // EventDispatcher::EventDispatcher();
    // Application::instance = this;
    initialize(param);
}

Application::~Application() {
    // Cleanup resources if needed
}

void Application::initialize(const std::string& param) {
    _services.clear();
    _objects.clear();
    // _time = new Time(); // Example initialization
    // _input = new Input(); // Example initialization
    // _servicesManager = new Services(); // Example initialization

    running = false;
    tabstop = (param == "tabstop");

    // Add required services first
    addService("time");
    addService("input");

    // Add optional (game-defined) services next
    // addOptionalServices();

    // Add events and rendering services last - got to;
    addService("tween");
    addService("events");
    addService("graphics");
    addService("physics");

    // Start all the services
    initServices(param);
}

void Application::addService(const std::string& serviceName) {
    std::shared_ptr<Service> service = createService(serviceName);
    if(service) {
        _services.push_back(service);
    }
}

void Application::initServices(const std::string& param) {
    for (auto& service : _services) {
        // FIXME: call the line below.
        // service->initialize(param);
    }
}

std::shared_ptr<Service> Application::createService(
    const std::string& serviceName) {
    if (serviceName == "event") {
        return std::make_shared<EventService>();
        // TODO: Add Physics Service.
        // } else if (serviceName == "time") {
        //     return std::make_shared<TimeService>();
    }
    // Handle unknown service
    return nullptr;
}

void Application::focus() {
    // Hack hack hack should be the input system
    // Graphics::instance.focus();
}

void Application::run() {
    // core game loop here
    realizeObjects();
    // Graphics::instance.scene.updateMatrixWorld();FIXME: call this.
    // lastFrameTime = Date::now(); // FIXME: replace with actual logic
    running = true;
    runloop();
}

void Application::runloop() {
    while (running) {
        updateServices();
        // FIXME: Correctly implement this method. Check Vizi's application.js
        // lastFrameTime = Date::now(); // Example usage, replace with actual
        // logic Add appropriate logic here

        // Overall idea
        // while (user does not exit)
        //     check for user input
        //     run AI
        //     move objects
        //     resolve collisions
        //     draw graphics
        //     play sounds
        // end while
    }
}

void Application::updateServices() {
    for (auto& service : _services) {
        service->update();
    }
}

void Application::updateObjects() {
    for (auto& object : _objects) {
        object->update();
    }
}

void Application::addObject(std::shared_ptr<Creation> o) {
    _objects.push_back(o);
    if (running) {
        o->realize();
    }
}

void Application::removeObject(std::shared_ptr<Creation> o) {
    auto it = std::find(_objects.begin(), _objects.end(), o);
    if (it != _objects.end()) {
        _objects.erase(it);
    }
}

void Application::realizeObjects() {
    for (auto& object : _objects) {
        object->realize();
    }
}

// void Application::onMouseMove(const MouseEvent& event) {
//     if (mouseDelegate && mouseDelegate->onMouseMove) {
//         mouseDelegate->onMouseMove(event);
//     }
// }

// void Application::onMouseDown(const MouseEvent& event) {
//     if (mouseDelegate && mouseDelegate->onMouseDown) {
//         mouseDelegate->onMouseDown(event);
//     }
// }

// void Application::onMouseUp(const MouseEvent& event) {
//     if (mouseDelegate && mouseDelegate->onMouseUp) {
//         mouseDelegate->onMouseUp(event);
//     }
// }

// void Application::onMouseClick(const MouseEvent& event) {
//     if (mouseDelegate && mouseDelegate->onMouseClick) {
//         mouseDelegate->onMouseClick(event);
//     }
// }

// void Application::onMouseDoubleClick(const MouseEvent& event) {
//     if (mouseDelegate && mouseDelegate->onMouseDoubleClick) {
//         mouseDelegate->onMouseDoubleClick(event);
//     }
// }

// void Application::onMouseScroll(const MouseScrollEvent& event) {
//     if (mouseDelegate && mouseDelegate->onMouseScroll) {
//         mouseDelegate->onMouseScroll(event);
//     }
// }

// void Application::onKeyDown(const KeyEvent& event) {
//     if (keyboardDelegate && keyboardDelegate->onKeyDown) {
//         keyboardDelegate->onKeyDown(event);
//     }
// }

// void Application::onKeyUp(const KeyEvent& event) {
//     if (keyboardDelegate && keyboardDelegate->onKeyUp) {
//         keyboardDelegate->onKeyUp(event);
//     }
// }

// void Application::onKeyPress(const KeyEvent& event) {
//     if (keyboardDelegate && keyboardDelegate->onKeyPress) {
//         keyboardDelegate->onKeyPress(event);
//     }
// }

// void Application::handleMouseMove(const MouseEvent& event) {
//     if (Application::instance && Application::instance->onMouseMove) {
//         Application::instance->onMouseMove(event);
//     }
// }

// void Application::handleMouseDown(const MouseEvent& event) {
//     if (Application::instance && Application::instance->onMouseDown) {
//         Application::instance->onMouseDown(event);
//     }
// }

// void Application::handleMouseUp(const MouseEvent& event) {
//     if (Application::instance && Application::instance->onMouseUp) {
//         Application::instance->onMouseUp(event);
//     }
// }

// void Application::handleMouseClick(const MouseEvent& event) {
//     if (Application::instance && Application::instance->onMouseClick) {
//         Application::instance->onMouseClick(event);
//     }
// }

// void Application::handleMouseDoubleClick(const MouseEvent& event) {
//     if (Application::instance && Application::instance->onMouseDoubleClick) {
//         Application::instance->onMouseDoubleClick(event);
//     }
// }

// void Application::handleMouseScroll(const MouseScrollEvent& event) {
//     if (Application::instance && Application::instance->onMouseScroll) {
//         Application::instance->onMouseScroll(event);
//     }
// }

// void Application::handleKeyDown(const KeyEvent& event) {
//     if (Application::instance && Application::instance->onKeyDown) {
//         Application::instance->onKeyDown(event);
//     }
// }

// void Application::handleKeyUp(const KeyEvent& event) {
//     if (Application::instance && Application::instance->onKeyUp) {
//         Application::instance->onKeyUp(event);
//     }
// }

// void Application::handleKeyPress(const KeyEvent& event) {
//     if (Application::instance && Application::instance->onKeyPress) {
//         Application::instance->onKeyPress(event);
//     }
// }

}  // namespace Genesis
