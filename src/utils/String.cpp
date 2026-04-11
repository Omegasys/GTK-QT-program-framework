#include <MyFramework/utils/String.h>
#include <sstream>
#include <algorithm>

namespace MyFramework {

std::vector<std::string> String::split(const std::string& str, char delim) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;

    while (std::getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}

std::string String::trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end   = str.find_last_not_of(" \t\n\r");

    if (start == std::string::npos)
        return "";

    return str.substr(start, end - start + 1);
}

std::string String::toLower(const std::string& str) {
    std::string out = str;
    std::transform(out.begin(), out.end(), out.begin(), ::tolower);
    return out;
}

} // namespace MyFramework
