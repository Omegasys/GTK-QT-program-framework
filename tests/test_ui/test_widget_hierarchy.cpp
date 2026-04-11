#include <MyFramework/ui/Widget.h>
#include <iostream>

using namespace MyFramework;

void run_widget_hierarchy_tests() {
    std::cout << "[TEST] Widget Hierarchy\n";

    Widget parent;
    Widget child(&parent);

    if (child.parent() == &parent)
        std::cout << "  ✔ Parent-child relationship works\n";
    else
        std::cout << "  ✖ Parent-child relationship failed\n";

    if (parent.children().size() == 1)
        std::cout << "  ✔ Child registered in parent\n";
    else
        std::cout << "  ✖ Child not registered\n";
}
