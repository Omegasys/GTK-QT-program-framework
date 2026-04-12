#pragma once

#include <string>
#include <unordered_map>

/*
 * EditorContext
 * ------------------------------------------------------------
 * Holds shared systems and configuration data.
 */

class EditorContext {
public:
    EditorContext();

    bool loadConfig(const std::string& path);

    const std::string& getValue(const std::string& key) const;

private:
    std::unordered_map<std::string, std::string> m_config;
};
