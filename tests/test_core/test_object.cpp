#include <MyFramework/core/Object.h>
#include <iostream>

using namespace MyFramework;

void run_object_tests() {
    std::cout << "[TEST] Object\n";

    Object parent;
    Object child(&parent);

    if (child.parent() == &parent)
        std::cout << "  ✔ Parent assignment passed\n";
    else
        std::cout << "  ✖ Parent assignment failed\n";
}
