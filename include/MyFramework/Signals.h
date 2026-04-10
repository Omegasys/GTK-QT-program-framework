#pragma once

#include <functional>
#include <vector>
#include <algorithm>
#include <cstddef>

namespace MyFramework {

/**
 * @brief A connection handle for a signal-slot connection.
 */
class Connection {
public:
    Connection() : m_id(0), m_valid(false) {}

    Connection(std::size_t id) : m_id(id), m_valid(true) {}

    std::size_t id() const { return m_id; }

    bool isValid() const { return m_valid; }

    void invalidate() { m_valid = false; }

private:
    std::size_t m_id;
    bool m_valid;
};

/**
 * @brief Signal class (Qt-style signal/slot system).
 *
 * Example:
 * Signal<int> valueChanged;
 *
 * valueChanged.connect([](int v) {
 *     // handle value
 * });
 *
 * valueChanged.emit(42);
 */
template<typename... Args>
class Signal {
public:
    Signal() : m_nextId(1) {}

    ~Signal() = default;

    /**
     * @brief Connects a slot (callback) to the signal.
     */
    Connection connect(std::function<void(Args...)> slot) {
        std::size_t id = m_nextId++;
        m_slots.emplace_back(id, std::move(slot));
        return Connection(id);
    }

    /**
     * @brief Disconnects a slot using its connection.
     */
    void disconnect(const Connection& connection) {
        if (!connection.isValid())
            return;

        auto it = std::remove_if(
            m_slots.begin(),
            m_slots.end(),
            [&](const Slot& s) {
                return s.id == connection.id();
            }
        );

        m_slots.erase(it, m_slots.end());
    }

    /**
     * @brief Emits the signal to all connected slots.
     */
    void emit(Args... args) {
        for (auto& slot : m_slots) {
            if (slot.func) {
                slot.func(args...);
            }
        }
    }

    /**
     * @brief Removes all connected slots.
     */
    void clear() {
        m_slots.clear();
    }

    /**
     * @brief Returns number of connected slots.
     */
    std::size_t size() const {
        return m_slots.size();
    }

private:
    struct Slot {
        std::size_t id;
        std::function<void(Args...)> func;

        Slot(std::size_t i, std::function<void(Args...)> f)
            : id(i), func(std::move(f)) {}
    };

    std::vector<Slot> m_slots;
    std::size_t m_nextId;
};

} // namespace MyFramework
