#pragma once

#include <string>

/*
 * Panel
 * ------------------------------------------------------------
 * Base class for all editor panels.
 */

class Panel {
public:
    Panel(const std::string& name);
    virtual ~Panel();

    virtual void update() = 0;
    virtual void render() = 0;

    const std::string& getName() const;

protected:
    std::string m_name;
};
