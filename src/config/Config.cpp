#include <MyFramework/config/Config.h>

namespace MyFramework {

Config::Config() {}

void Config::setValue(const std::string& key, const std::string& value) {
    m_values[key] = value;
}

std::string Config::value(const std::string& key, const std::string& defaultValue) const {
    auto it = m_values.find(key);
    if (it != m_values.end())
        return it->second;
    return defaultValue;
}

bool Config::has(const std::string& key) const {
    return m_values.find(key) != m_values.end();
}

void Config::clear() {
    m_values.clear();
}

const std::unordered_map<std::string, std::string>& Config::values() const {
    return m_values;
}

} // namespace MyFramework
