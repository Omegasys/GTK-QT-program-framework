#include <MyFramework/ui/Layout.h>
#include <MyFramework/ui/Widget.h>
#include <iostream>

using namespace MyFramework;

void run_layout_tests() {
    std::cout << "[TEST] Layout Engine\n";

    Widget parent;
    parent.setSize(400, 400);

    Layout layout;
    layout.setParent(&parent);

    Widget child1(&parent);
    Widget child2(&parent);

    layout.addWidget(&child1);
    layout.addWidget(&child2);

    layout.apply();

    if (child1.width() > 0 && child2.width() > 0)
        std::cout << "  ✔ Layout applied sizes\n";
    else
        std::cout << "  ✖ Layout failed\n";
}
