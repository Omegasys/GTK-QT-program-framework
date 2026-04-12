#include "Panel.h"

Panel::Panel(const std::string& name)
    : m_name(name) {}

Panel::~Panel() = default;

const std::string& Panel::getName() const {
    return m_name;
}
