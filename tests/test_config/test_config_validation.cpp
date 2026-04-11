#include <MyFramework/config/ConfigParser.h>
#include <MyFramework/utils/FileSystem.h>
#include <iostream>

using namespace MyFramework;

void run_config_validation_tests() {
    std::cout << "[TEST] Config Validation\n";

    std::string path = "test_validation.tmp";

    FileSystem::writeFile(path,
        "valid_key=value\n"
        "invalid_line_without_equals\n"
    );

    Config config = ConfigParser::parseFile(path);

    if (config.value("valid_key") == "value")
        std::cout << "  ✔ Valid entry parsed\n";
    else
        std::cout << "  ✖ Valid entry failed\n";

    if (config.value("invalid_line_without_equals").empty())
        std::cout << "  ✔ Invalid line ignored\n";
    else
        std::cout << "  ✖ Invalid line not handled\n";
}
