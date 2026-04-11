#include <MyFramework/theme/ThemeParser.h>
#include <iostream>

using namespace MyFramework;

void run_theme_parser_tests() {
    std::cout << "[TEST] Theme Parser\n";

    std::string input =
        "#112233-445566-778899-255-10-12-8-000000-111111-222222";

    Theme theme = ThemeParser::parseThemeString(input);

    if (theme.opacity > 0.9f)
        std::cout << "  ✔ Opacity parsed\n";
    else
        std::cout << "  ✖ Opacity failed\n";

    if (theme.blur == 10)
        std::cout << "  ✔ Blur parsed\n";
    else
        std::cout << "  ✖ Blur failed\n";

    if (theme.cornerRadius == 12)
        std::cout << "  ✔ Corner radius parsed\n";
    else
        std::cout << "  ✖ Corner radius failed\n";
}
