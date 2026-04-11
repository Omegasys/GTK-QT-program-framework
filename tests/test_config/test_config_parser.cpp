#include <MyFramework/config/ConfigParser.h>
#include <MyFramework/utils/FileSystem.h>
#include <iostream>

using namespace MyFramework;

void run_config_parser_tests() {
    std::cout << "[TEST] Config Parser\n";

    std::string path = "test_config_parser.tmp";

    FileSystem::writeFile(path,
        "name=MyApp\n"
        "version=1.0\n"
    );

    Config config = ConfigParser::parseFile(path);

    if (config.value("name") == "MyApp")
        std::cout << "  ✔ Name parsed\n";
    else
        std::cout << "  ✖ Name parse failed\n";

    if (config.value("version") == "1.0")
        std::cout << "  ✔ Version parsed\n";
    else
        std::cout << "  ✖ Version parse failed\n";
}
