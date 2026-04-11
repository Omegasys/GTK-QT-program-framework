#include <MyFramework/core/Object.h>

namespace MyFramework {

Object::Object(Object* parent)
    : m_parent(nullptr) {
    setParent(parent);
}

Object::~Object() {
    for (auto child : m_children) {
        delete child;
    }
    m_children.clear();
}

void Object::setParent(Object* parent) {
    if (m_parent == parent) return;

    if (m_parent) {
        m_parent->removeChild(this);
    }

    m_parent = parent;

    if (m_parent) {
        m_parent->addChild(this);
    }
}

Object* Object::parent() const {
    return m_parent;
}

void Object::addChild(Object* child) {
    if (!child) return;
    m_children.push_back(child);
}

void Object::removeChild(Object* child) {
    m_children.erase(
        std::remove(m_children.begin(), m_children.end(), child),
        m_children.end()
    );
}

const std::vector<Object*>& Object::children() const {
    return m_children;
}

void Object::setName(const std::string& name) {
    m_name = name;
}

const std::string& Object::name() const {
    return m_name;
}

} // namespace MyFramework
