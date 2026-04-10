#pragma once

#include <MyFramework/utils/Color.h>

namespace MyFramework {

/**
 * @brief Represents a drawable surface.
 *
 * Could be:
 * - Window framebuffer
 * - Offscreen buffer
 * - Texture target
 */
class RenderTarget {
public:
    virtual ~RenderTarget() = default;

    /**
     * @brief Gets width.
     */
    virtual int width() const = 0;

    /**
     * @brief Gets height.
     */
    virtual int height() const = 0;

    /**
     * @brief Clears target with color.
     */
    virtual void clear(const Color& color) = 0;
};

} // namespace MyFramework
