#include <MyFramework/theme/ThemeParser.h>
#include <iostream>

using namespace MyFramework;

void run_timeframe_parsing_tests() {
    std::cout << "[TEST] Timeframe + Theme Format Parsing\n";

    std::string configLine =
        "08:00-12:00:#123456-654321-abcdef-255-10-12-8-000000-111111-222222";

    // Extract theme part manually (like ThemeManager does)
    size_t colon = configLine.find(':');
    std::string themeStr = configLine.substr(colon + 1);

    Theme theme = ThemeParser::parseThemeString(themeStr);

    if (theme.opacity > 0.9f)
        std::cout << "  ✔ Opacity parsed from timeframe config\n";
    else
        std::cout << "  ✖ Opacity parse failed\n";

    if (theme.blur == 10)
        std::cout << "  ✔ Blur parsed from timeframe config\n";
    else
        std::cout << "  ✖ Blur parse failed\n";
}
