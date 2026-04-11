#include <vector>
#include <functional>

namespace MyFramework {

/**
 * @brief Simple signal class (no header version).
 */
class SignalBase {
public:
    virtual ~SignalBase() = default;
};

template<typename... Args>
class Signal : public SignalBase {
public:
    using Slot = std::function<void(Args...)>;

    void connect(const Slot& slot) {
        m_slots.push_back(slot);
    }

    void emit(Args... args) {
        for (auto& slot : m_slots) {
            slot(args...);
        }
    }

private:
    std::vector<Slot> m_slots;
};

} // namespace MyFramework
