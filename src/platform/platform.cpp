#include <GQFusion/platform/platform.h>

namespace GQFusion {

static PlatformType s_type = PlatformType::Unknown;

void Platform::setType(PlatformType type) {
    s_type = type;
}

PlatformType Platform::getType() {
    return s_type;
}

bool Platform::isWindows() {
    return s_type == PlatformType::Windows;
}

bool Platform::isLinux() {
    return s_type == PlatformType::Linux;
}

bool Platform::isMac() {
    return s_type == PlatformType::Mac;
}

} // namespace GQFusion
