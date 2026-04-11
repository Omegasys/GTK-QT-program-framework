#pragma once

#include <MyFramework/ui/Widget.h>
#include <string>
#include <unordered_map>

class PropertyEditor : public MyFramework::Widget {
public:
    PropertyEditor(MyFramework::Window* parent);

    void update();

    void inspectObject(const std::string& objectId);

private:
    std::unordered_map<std::string, std::string> properties;
};
