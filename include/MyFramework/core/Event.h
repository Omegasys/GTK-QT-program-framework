#pragma once

#include <string>

namespace MyFramework {

/**
 * @brief Base event type.
 */
enum class EventType {
    None,
    KeyPress,
    KeyRelease,
    MouseMove,
    MousePress,
    MouseRelease,
    WindowResize,
    WindowClose,
    Custom
};

/**
 * @brief Base event class.
 */
class Event {
public:
    Event(EventType type = EventType::None);
    virtual ~Event() = default;

    /**
     * @brief Returns event type.
     */
    EventType type() const;

    /**
     * @brief Marks event as handled.
     */
    void setHandled(bool handled);

    /**
     * @brief Checks if event is handled.
     */
    bool isHandled() const;

    /**
     * @brief Optional event name (debugging / custom events).
     */
    void setName(const std::string& name);
    const std::string& name() const;

protected:
    EventType m_type;
    bool m_handled;
    std::string m_name;
};

/**
 * @brief Key event example.
 */
class KeyEvent : public Event {
public:
    KeyEvent(int keyCode, bool pressed);

    int keyCode() const;
    bool pressed() const;

private:
    int m_keyCode;
    bool m_pressed;
};

} // namespace MyFramework
