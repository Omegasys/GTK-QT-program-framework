#pragma once

#include <string>
#include <MyFramework/utils/Color.h>

namespace MyFramework {

/**
 * @brief Types of drawing operations.
 */
enum class DrawCommandType {
    Rect,
    RoundedRect,
    Text,
    Line,
    Image
};

/**
 * @brief A single render instruction.
 *
 * UI widgets generate these, renderer batches them.
 */
struct DrawCommand {
    DrawCommandType type;

    // Position & size
    float x = 0;
    float y = 0;
    float width = 0;
    float height = 0;

    // Visual properties
    Color color;

    // Optional text (for Text commands)
    std::string text;

    // Rounded corners
    float radius = 0.0f;

    // Z-order layering
    int zIndex = 0;
};

} // namespace MyFramework
