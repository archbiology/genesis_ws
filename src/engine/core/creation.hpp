#pragma once

#include <functional>  // for std::function
#include <memory>      // for std::shared_ptr
#include <string>
#include <vector>

namespace Genesis {

class Component;  // Forward declaration

/**
 * @brief Represents a creation in the Genesis engine.
 *
 * This class manages hierarchical relationships, components, and
 * initialization/update routines.
 */
class Creation : public std::enable_shared_from_this<Creation> {
   public:
    /**
     * @brief Constructor for Creation objects.
     *
     * @param autoCreateTransform Whether to automatically create a transform
     * component.
     */
    Creation(bool autoCreateTransform = true);

    /**
     * @brief Get the ID of the creation.
     *
     * @return The ID of the creation.
     */
    int getID() const;

    // -------------------------------------------------------------------------
    // Hierarchy methods
    // -------------------------------------------------------------------------
    /**
     * @brief Sets the parent of the creation.
     *
     * @param parent The parent creation to set.
     */
    void setParent(std::shared_ptr<Creation> parent);

    /**
     * @brief Adds a child creation to this creation.
     *
     * @param child The child creation to add.
     */
    void addChild(std::shared_ptr<Creation> child);

    /**
     * @brief Removes a child creation from this creation.
     *
     * @param child The child creation to remove.
     */
    void removeChild(std::shared_ptr<Creation> child);

    /**
     * @brief Retrieves a child creation by index.
     *
     * @param index The index of the child creation.
     * @return The child creation at the specified index, or nullptr if index is
     * out of bounds.
     */
    std::shared_ptr<Creation> getChild(size_t index) const;

    // -------------------------------------------------------------------------
    // Component methods
    // -------------------------------------------------------------------------
    /**
     * @brief Adds a component to this creation.
     *
     * @param component The component to add.
     */
    void addComponent(std::shared_ptr<Component> component);

    /**
     * @brief Removes a component from this creation.
     *
     * @param component The component to remove.
     */
    void removeComponent(std::shared_ptr<Component> component);

    /**
     * @brief Removes all components from this creation.
     */
    void removeAllComponents();

    /**
     * @brief Retrieves the first component of a given type attached to this
     * creation.
     *
     * @param type The type of the component to retrieve.
     * @return The first component of the specified type, or nullptr if not
     * found.
     */
    std::shared_ptr<Component> getComponent(const std::type_info &type) const;

    /**
     * @brief Retrieves all components of a given type attached to this
     * creation.
     *
     * @param type The type of the components to retrieve.
     * @return A vector of all components of the specified type.
     */
    std::vector<std::shared_ptr<Component>> getComponents(
        const std::type_info &type) const;

    // -------------------------------------------------------------------------
    // Initialize methods
    // -------------------------------------------------------------------------
    /**
     * @brief Initializes the creation and its components.
     *
     * This method prepares the creation and its components for use.
     */
    void realize();

    // --------------
    // Update methods
    // --------------
    /**
     * @brief Updates the creation and its components.
     *
     * This method updates the creation and its components during each frame or
     * time step.
     */
    void update();

    // -------------------------------------------------------------------------
    // Traversal and query methods
    // -------------------------------------------------------------------------
    /**
     * @brief Traverses the creation hierarchy and performs a callback on each
     * node.
     *
     * @param callback The function to call on each creation node.
     */
    void traverse(std::function<void(std::shared_ptr<Creation>)> callback);

    /**
     * @brief Finds the first child creation with a matching name.
     *
     * @param name The name of the child creation to find.
     * @return The first child creation with the specified name, or nullptr if
     * not found.
     */
    std::shared_ptr<Creation> findNode(const std::string &query);

    /**
     * @brief Finds all child creations matching a query.
     *
     * @param query The query string or pattern to match against creation names.
     * @return A vector of all child creations matching the query.
     */
    std::vector<std::shared_ptr<Creation>> findNodes(const std::string &query);

   private:
    /**
     * @brief The next available ID for a creation.
     */
    static int nextId;

    /**
     * @brief The unique identifier of the creation.
     */
    int _id;

    /**
     * @brief The parent creation of this creation.
     */
    std::shared_ptr<Creation> _parent;

    /**
     * @brief List of child creations.
     */
    std::vector<std::shared_ptr<Creation>> _children;

    /**
     * @brief List of components attached to this creation.
     */
    std::vector<std::shared_ptr<Component>> _components;

    /**
     * @brief The name of the creation.
     */
    std::string name;

    /**
     * @brief Flag indicating if the creation is currently being realized.
     */
    bool _realizing;

    /**
     * @brief Flag indicating if the creation has been fully realized.
     */
    bool _realized;

    /**
     * @brief Initializes all components attached to this creation.
     *
     * This method initializes all components that belong to this creation.
     */
    void realizeComponents();

    /**
     * @brief Initializes all child creations attached to this creation.
     *
     * This method initializes all child creations that belong to this creation.
     */
    void realizeChildren();

    /**
     * @brief Updates all components attached to this creation.
     *
     * This method updates all components that belong to this creation.
     */
    void updateComponents();

    /**
     * @brief Updates all child creations attached to this creation.
     *
     * This method updates all child creations that belong to this creation.
     */
    void updateChildren();

    /**
     * @brief Callback function used for finding nodes based on a query.
     *
     * This function is used to traverse through nodes and find those that match
     * the specified query criteria.
     *
     * @param node The current node being evaluated during traversal.
     * @param query The query used to filter nodes. Can be a string, regular
     * expression, or type/function pointer.
     * @param found A vector to store the nodes that match the query.
     *
     * @note The query parameter can be a string for matching node names, a
     * regular expression for more complex matching, or a type/function pointer
     * to find nodes of a specific type or matching a specific condition.
     */
    void findCallback(std::shared_ptr<Creation> node, const std::string &query,
                      std::vector<std::shared_ptr<Creation>> &found);
};

/**
 * @brief Base class for components that can be attached to a Creation.
 *
 * Components are modular parts that can be added to a Creation to provide
 * specific functionality. Derived classes should implement the realize() and
 * update() methods for initialization and updating logic.
 */
class Component {
   public:
    /**
     * @brief Initializes the component.
     *
     * This method should be overridden in derived classes to perform
     * initialization tasks. It is called when the component is added to a
     * Creation and is being prepared for use.
     */
    virtual void realize() = 0;

    /**
     * @brief Updates the component.
     *
     * This method should be overridden in derived classes to update the state
     * of the component. It is called each frame or time step to update the
     * component's behavior.
     */
    virtual void update() = 0;

    /**
     * @brief Sets the Creation that owns this component.
     *
     * @param creation The Creation to which this component belongs.
     */
    void setCreation(std::shared_ptr<Creation> creation);

    /**
     * @brief The Creation to which this component belongs.
     */
    std::shared_ptr<Creation> _creation;
};
}  // namespace Genesis