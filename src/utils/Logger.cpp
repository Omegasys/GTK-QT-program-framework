#include <MyFramework/utils/Logger.h>
#include <iostream>
#include <ctime>

namespace MyFramework {

static std::string timestamp() {
    std::time_t t = std::time(nullptr);
    std::tm* tm = std::localtime(&t);

    char buffer[32];
    std::strftime(buffer, sizeof(buffer), "%H:%M:%S", tm);
    return buffer;
}

void Logger::info(const std::string& msg) {
    std::cout << "[INFO][" << timestamp() << "] " << msg << "\n";
}

void Logger::warn(const std::string& msg) {
    std::cout << "[WARN][" << timestamp() << "] " << msg << "\n";
}

void Logger::error(const std::string& msg) {
    std::cerr << "[ERROR][" << timestamp() << "] " << msg << "\n";
}

} // namespace MyFramework
