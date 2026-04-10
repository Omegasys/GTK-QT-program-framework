#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace MyFramework {

/**
 * @brief Base class for all framework objects.
 *
 * Provides:
 * - Object hierarchy
 * - Parent/child relationships
 * - Basic identification
 */
class Object {
public:
    explicit Object(Object* parent = nullptr);
    virtual ~Object();

    /**
     * @brief Sets parent object.
     */
    void setParent(Object* parent);

    /**
     * @brief Gets parent object.
     */
    Object* parent() const;

    /**
     * @brief Adds a child object.
     */
    void addChild(Object* child);

    /**
     * @brief Removes a child object.
     */
    void removeChild(Object* child);

    /**
     * @brief Gets all children.
     */
    const std::vector<Object*>& children() const;

    /**
     * @brief Object name (useful for debugging / config mapping).
     */
    void setName(const std::string& name);
    const std::string& name() const;

protected:
    Object* m_parent;
    std::vector<Object*> m_children;
    std::string m_name;
};

} // namespace MyFramework
