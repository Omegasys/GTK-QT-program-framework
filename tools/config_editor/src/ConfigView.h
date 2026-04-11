#pragma once

#include <string>
#include <MyFramework/ui/Widget.h>

class ConfigTreeModel;

class ConfigView : public MyFramework::Widget {
public:
    ConfigView(MyFramework::Window* parent);

    void loadFile(const std::string& path);
    void update();

    std::string getCurrentConfig() const;

private:
    ConfigTreeModel* model = nullptr;
    std::string currentFile;
    std::string configData;
};
