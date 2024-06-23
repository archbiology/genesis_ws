#include "app.hpp"

#include <memory>

#include "core/service.hpp"
#include "events/event_service.hpp"
#include "physics/dynamics/dynamics_service.hpp"

namespace Genesis {

App::App(const std::string& param)
    : running(false),
      tabstop(false),
      _time(nullptr),
      _input(nullptr),
      _servicesManager(nullptr) {
    // EventDispatcher::EventDispatcher();
    // App::instance = this;
    initialize(param);
}

App::~App() {
    // Cleanup resources if needed
}

void App::initialize(const std::string& param) {
    // -----------
    // Genesis 1:1
    // -----------
    heavens = ItCameToPass(Creation);
    earth = ItCameToPass(Creation);

    // ----------------------------------------
    // Genesis 1:3-5 (Lightday), not "Sun day")
    // ----------------------------------------
    light = ItCameToPass(Creation);
    day = light;

    // ------------------------------------------------------
    // Genesis 1:7,8 (The second day: Skyday, not "Moon day")
    // ------------------------------------------------------
    sky = heavens;

    // ---------------------------------------------------------
    // Genesis 1:9-13 (The third day: Greenday, not "Tiu's day")
    // ---------------------------------------------------------
    land = earth;
    // grass, herbs, trees

    // -------------------------------------------------------------
    // Genesis 1:14-19 (The fouth day: Lampsday, not "Wooden's day")
    // -------------------------------------------------------------
    // sun, moon, stars;

    // --------------------------------------------------------------
    // Genesis 1:20-23 (The fifth day: Fishbirdday, not "Thor's day")
    // --------------------------------------------------------------
    // fish, birds;

    // ----------------------------------------------------------
    // Genesis 1:24-31 (The sixth day: Walkersday, not "Fry day")
    // ----------------------------------------------------------
    // repitiles, animals;
    // man, woman;

    // --------------------------------------------------------------
    // Genesis 2:1-4 (The seventh day: Restingday, not "Saturn day")
    // --------------------------------------------------------------
    //  resting;

    _services.clear();
    objects.clear();
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
    addService("physics::dynamics");

    // Start all the services
    initServices(param);
}

void App::addService(const std::string& serviceName) {
    std::shared_ptr<Service> service = createService(serviceName);
    if (service) {
        _services.push_back(service);
    }
}

void App::initServices(const std::string& param) {
    for (auto& service : _services) {
        service->initialize(this);
    }
}

std::shared_ptr<Service> App::createService(const std::string& serviceName) {
    if (serviceName == "event") {
        return std::make_shared<EventService>();
        // } else if (serviceName == "time") {
        //     return std::make_shared<TimeService>();
    }

    if (serviceName == "physics::dynamics") {
        return std::make_shared<DynamicsService>();
    }

    return nullptr;
}

void App::focus() {
    // Hack hack hack should be the input system
    // Graphics::instance.focus();
}

void App::run() {
    // core game loop here
    realizeObjects();
    // Graphics::instance.scene.updateMatrixWorld();FIXME: call this.
    // lastFrameTime = Date::now(); // FIXME: replace with actual logic
    running = true;
    runloop();
}

void App::runloop() {
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

void App::updateServices() {
    for (auto& service : _services) {
        service->update();
    }
}

void App::updateObjects() {
    for (auto& object : objects) {
        object->update();
    }
}

void App::addObject(std::shared_ptr<Creation> o) {
    objects.push_back(o);
    if (running) {
        o->realize();
    }
}

void App::removeObject(std::shared_ptr<Creation> o) {
    auto it = std::find(objects.begin(), objects.end(), o);
    if (it != objects.end()) {
        objects.erase(it);
    }
}

void App::realizeObjects() {
    for (auto& object : objects) {
        object->realize();
    }
}

// void App::onMouseMove(const MouseEvent& event) {
//     if (mouseDelegate && mouseDelegate->onMouseMove) {
//         mouseDelegate->onMouseMove(event);
//     }
// }

// void App::onMouseDown(const MouseEvent& event) {
//     if (mouseDelegate && mouseDelegate->onMouseDown) {
//         mouseDelegate->onMouseDown(event);
//     }
// }

// void App::onMouseUp(const MouseEvent& event) {
//     if (mouseDelegate && mouseDelegate->onMouseUp) {
//         mouseDelegate->onMouseUp(event);
//     }
// }

// void App::onMouseClick(const MouseEvent& event) {
//     if (mouseDelegate && mouseDelegate->onMouseClick) {
//         mouseDelegate->onMouseClick(event);
//     }
// }

// void App::onMouseDoubleClick(const MouseEvent& event) {
//     if (mouseDelegate && mouseDelegate->onMouseDoubleClick) {
//         mouseDelegate->onMouseDoubleClick(event);
//     }
// }

// void App::onMouseScroll(const MouseScrollEvent& event) {
//     if (mouseDelegate && mouseDelegate->onMouseScroll) {
//         mouseDelegate->onMouseScroll(event);
//     }
// }

// void App::onKeyDown(const KeyEvent& event) {
//     if (keyboardDelegate && keyboardDelegate->onKeyDown) {
//         keyboardDelegate->onKeyDown(event);
//     }
// }

// void App::onKeyUp(const KeyEvent& event) {
//     if (keyboardDelegate && keyboardDelegate->onKeyUp) {
//         keyboardDelegate->onKeyUp(event);
//     }
// }

// void App::onKeyPress(const KeyEvent& event) {
//     if (keyboardDelegate && keyboardDelegate->onKeyPress) {
//         keyboardDelegate->onKeyPress(event);
//     }
// }

// void App::handleMouseMove(const MouseEvent& event) {
//     if (App::instance && App::instance->onMouseMove) {
//         App::instance->onMouseMove(event);
//     }
// }

// void App::handleMouseDown(const MouseEvent& event) {
//     if (App::instance && App::instance->onMouseDown) {
//         App::instance->onMouseDown(event);
//     }
// }

// void App::handleMouseUp(const MouseEvent& event) {
//     if (App::instance && App::instance->onMouseUp) {
//         App::instance->onMouseUp(event);
//     }
// }

// void App::handleMouseClick(const MouseEvent& event) {
//     if (App::instance && App::instance->onMouseClick) {
//         App::instance->onMouseClick(event);
//     }
// }

// void App::handleMouseDoubleClick(const MouseEvent& event) {
//     if (App::instance && App::instance->onMouseDoubleClick) {
//         App::instance->onMouseDoubleClick(event);
//     }
// }

// void App::handleMouseScroll(const MouseScrollEvent& event) {
//     if (App::instance && App::instance->onMouseScroll) {
//         App::instance->onMouseScroll(event);
//     }
// }

// void App::handleKeyDown(const KeyEvent& event) {
//     if (App::instance && App::instance->onKeyDown) {
//         App::instance->onKeyDown(event);
//     }
// }

// void App::handleKeyUp(const KeyEvent& event) {
//     if (App::instance && App::instance->onKeyUp) {
//         App::instance->onKeyUp(event);
//     }
// }

// void App::handleKeyPress(const KeyEvent& event) {
//     if (App::instance && App::instance->onKeyPress) {
//         App::instance->onKeyPress(event);
//     }
// }

}  // namespace Genesis
