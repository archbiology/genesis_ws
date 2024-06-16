#include "component.hpp"

namespace Genesis {

Component::Component() : _creation(nullptr), _realized(false) {
    // Constructor implementation
}

// Creation* Component::getCreation() const { return _creation; }
std::shared_ptr<Creation> Component::getCreation() const { return _creation; }

void Component::setCreation(std::shared_ptr<Creation> creation) {
    // void Component::setCreation(Creation* creation) {
    _creation = creation;
}

void Component::realize() { _realized = true; }

void Component::update() {
    // Update implementation
}

}  // namespace Genesis
