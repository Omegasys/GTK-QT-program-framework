#include <MyFramework/core/Event.h>
#include <MyFramework/ui/Widget.h>

namespace MyFramework {

/**
 * @brief Simple event dispatcher helper.
 */
class EventDispatcher {
public:
    static bool dispatch(Event& event, Widget* root) {
        if (!root || event.isHandled())
            return false;

        // Let root handle first
        if (root->handleEvent(event))
            return true;

        // Propagate to children
        for (auto child : root->children()) {
            Widget* widget = dynamic_cast<Widget*>(child);
            if (widget && dispatch(event, widget))
                return true;
        }

        return false;
    }
};

} // namespace MyFramework
