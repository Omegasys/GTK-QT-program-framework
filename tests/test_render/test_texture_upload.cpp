#include <MyFramework/render/Texture.h>
#include <iostream>

using namespace MyFramework;

void run_texture_tests() {
    std::cout << "[TEST] Texture\n";

    Texture texture;

    bool loaded = texture.loadFromFile("dummy.png");

    if (loaded && texture.isValid())
        std::cout << "  ✔ Texture loaded (stub)\n";
    else
        std::cout << "  ✖ Texture load failed\n";

    std::cout << "  Size: " << texture.width()
              << "x" << texture.height() << "\n";
}
