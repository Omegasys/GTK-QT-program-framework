#pragma once

#include <functional>
#include <unordered_map>
#include <vector>
#include <typeindex>
#include <memory>

#include <GQFusion/core/Event.h>

namespace GQFusion {

class EventDispatcher {
public:
    EventDispatcher() = default;
    ~EventDispatcher() = default;

    // ------------------------------------------------------------
    // Listener Registration
    // ------------------------------------------------------------

    template<typename EventType>
    void addListener(std::function<void(const EventType&)> callback) {
        auto type = std::type_index(typeid(EventType));

        auto wrapper = [callback](const Event& e) {
            callback(static_cast<const EventType&>(e));
        };

        listeners[type].push_back(wrapper);
    }

    // ------------------------------------------------------------
    // Remove All Listeners for Event Type
    // ------------------------------------------------------------

    template<typename EventType>
    void removeListeners() {
        auto type = std::type_index(typeid(EventType));
        listeners.erase(type);
    }

    // ------------------------------------------------------------
    // Dispatch Event
    // ------------------------------------------------------------

    void dispatch(const Event& event) {
        auto type = std::type_index(typeid(event));

        auto it = listeners.find(type);
        if (it == listeners.end())
            return;

        for (auto& callback : it->second) {
            callback(event);
        }
    }

    // ------------------------------------------------------------
    // Clear All Listeners
    // ------------------------------------------------------------

    void clear() {
        listeners.clear();
    }

private:
    using Listener = std::function<void(const Event&)>;
    std::unordered_map<std::type_index, std::vector<Listener>> listeners;
};

} // namespace GQFusion
