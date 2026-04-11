#pragma once

#include <vector>
#include <memory>

namespace GQFusion {

class DrawCommand;

/**
 * @brief Multi-threaded UI command scheduler.
 *
 * Builds render commands in parallel before submission to GPU.
 */
class CommandScheduler {
public:
    CommandScheduler() = default;
    ~CommandScheduler() = default;

    void reset();

    void addCommand(const std::shared_ptr<DrawCommand>& cmd);

    void execute(); // merge + finalize

private:
    std::vector<std::shared_ptr<DrawCommand>> commands;
};

} // namespace GQFusion
