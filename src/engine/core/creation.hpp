#pragma once

#include <functional>
#include <memory>
#include <string>
#include <vector>

namespace Genesis {

class Component;  // Forward declaration

class Creation : public std::enable_shared_from_this<Creation> {
   public:
    Creation(bool autoCreateTransform = true);

    int getID() const;

    // Hierarchy methods
    void setParent(std::shared_ptr<Creation> parent);
    void addChild(std::shared_ptr<Creation> child);
    void removeChild(std::shared_ptr<Creation> child);
    std::shared_ptr<Creation> getChild(size_t index) const;

    // Component methods
    void addComponent(std::shared_ptr<Component> component);
    void removeComponent(std::shared_ptr<Component> component);
    void removeAllComponents();
    std::shared_ptr<Component> getComponent(const std::type_info &type) const;
    std::vector<std::shared_ptr<Component>> getComponents(
        const std::type_info &type) const;

    // Initialize methods
    void realize();

    // Update methods
    void update();

    // Traversal and query methods
    void traverse(std::function<void(std::shared_ptr<Creation>)> callback);
    std::shared_ptr<Creation> findNode(const std::string &query);
    std::vector<std::shared_ptr<Creation>> findNodes(const std::string &query);

   private:
    static int nextId;
    int _id;
    std::shared_ptr<Creation> _parent;
    std::vector<std::shared_ptr<Creation>> _children;
    std::vector<std::shared_ptr<Component>> _components;
    std::string name;
    bool _realizing;
    bool _realized;

    void realizeComponents();
    void realizeChildren();
    void updateComponents();
    void updateChildren();
    void findCallback(std::shared_ptr<Creation> node, const std::string &query,
                      std::vector<std::shared_ptr<Creation>> &found);
};

class Component {
   public:
    virtual void realize() = 0;
    virtual void update() = 0;
    void setCreation(std::shared_ptr<Creation> creation);

    // protected:
    std::shared_ptr<Creation> _creation;
};
}  // namespace Genesis