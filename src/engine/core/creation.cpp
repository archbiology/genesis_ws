#include "creation.hpp"

#include <algorithm>
#include <stdexcept>

namespace Genesis {

int Creation::nextId = 0;

Creation::Creation(bool autoCreateTransform)
    : _id(nextId++), _parent(nullptr), _realizing(false), _realized(false) {
    if (autoCreateTransform) {
        // Add default transform component, assuming Transform is derived from
        // Component addComponent(std::make_shared<Transform>());
    }
}

int Creation::getID() const { return _id; }

void Creation::setParent(std::shared_ptr<Creation> parent) { _parent = parent; }

void Creation::addChild(std::shared_ptr<Creation> child) {
    if (!child) {
        throw std::runtime_error("Cannot add a null child");
    }

    if (child->_parent) {
        throw std::runtime_error("Child is already attached to a Creation");
    }

    child->setParent(shared_from_this());
    _children.push_back(child);

    if ((_realizing || _realized) && !child->_realized) {
        child->realize();
    }
}

void Creation::removeChild(std::shared_ptr<Creation> child) {
    auto it = std::find(_children.begin(), _children.end(), child);
    if (it != _children.end()) {
        _children.erase(it);
        child->removeAllComponents();
        child->setParent(nullptr);
        child->_realized = child->_realizing = false;
    }
}

std::shared_ptr<Creation> Creation::getChild(size_t index) const {
    if (index >= _children.size()) {
        return nullptr;
    }
    return _children[index];
}

void Creation::addComponent(std::shared_ptr<Component> component) {
    if (!component) {
        throw std::runtime_error("Cannot add a null component");
    }

    if (component->_creation) {
        throw std::runtime_error("Component is already attached to a Creation");
    }

    // _components.push_back(component);
    // component->setCreation(shared_from_this());

    // if ((_realizing || _realized) && !component->_realized) {
    //     component->realize();
    // }
}

void Creation::removeComponent(std::shared_ptr<Component> component) {
    auto it = std::find(_components.begin(), _components.end(), component);
    if (it != _components.end()) {
        _components.erase(it);
        component->setCreation(nullptr);
    }
}

void Creation::removeAllComponents() {
    for (auto& component : _components) {
        component->setCreation(nullptr);
    }
    _components.clear();
}

std::shared_ptr<Component> Creation::getComponent(
    const std::type_info& type) const {
    for (const auto& component : _components) {
        if (typeid(*component) == type) {
            return component;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Component>> Creation::getComponents(
    const std::type_info& type) const {
    std::vector<std::shared_ptr<Component>> components;
    for (const auto& component : _components) {
        if (typeid(*component) == type) {
            components.push_back(component);
        }
    }
    return components;
}

void Creation::realize() {
    _realizing = true;
    realizeComponents();
    realizeChildren();
    _realized = true;
}

void Creation::realizeComponents() {
    for (auto& component : _components) {
        if (!component->_creation->_realized) {
            component->setCreation(shared_from_this());
            component->realize();
        }
    }
}

void Creation::realizeChildren() {
    for (auto& child : _children) {
        if (!child->_realized) {
            child->realize();
        }
    }
}

void Creation::update() {
    updateComponents();
    updateChildren();
}

void Creation::updateComponents() {
    for (auto& component : _components) {
        component->update();
    }
}

void Creation::updateChildren() {
    for (auto& child : _children) {
        child->update();
    }
}

void Creation::traverse(
    std::function<void(std::shared_ptr<Creation>)> callback) {
    callback(shared_from_this());
    for (auto& child : _children) {
        child->traverse(callback);
    }
}

void Creation::findCallback(std::shared_ptr<Creation> node,
                            const std::string& query,
                            std::vector<std::shared_ptr<Creation>>& found) {
    if (node->name == query) {
        found.push_back(node);
    }
    // Extend this logic to handle other types of queries if needed
}

std::shared_ptr<Creation> Creation::findNode(const std::string& query) {
    std::vector<std::shared_ptr<Creation>> found;
    traverse([this, &query, &found](std::shared_ptr<Creation> node) {
        findCallback(node, query, found);
    });
    return found.empty() ? nullptr : found.front();
}

std::vector<std::shared_ptr<Creation>> Creation::findNodes(
    const std::string& query) {
    std::vector<std::shared_ptr<Creation>> found;
    traverse([this, &query, &found](std::shared_ptr<Creation> node) {
        findCallback(node, query, found);
    });
    return found;
}

void Component::setCreation(std::shared_ptr<Creation> creation) {
    _creation = creation;
}
}  // namespace Genesis