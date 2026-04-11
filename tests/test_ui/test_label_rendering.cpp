#include <MyFramework/ui/Label.h>
#include <iostream>

using namespace MyFramework;

void run_label_tests() {
    std::cout << "[TEST] Label Rendering\n";

    Label label;
    label.setText("Test Label");

    if (label.text() == "Test Label")
        std::cout << "  ✔ Label text set correctly\n";
    else
        std::cout << "  ✖ Label text failed\n";
}
