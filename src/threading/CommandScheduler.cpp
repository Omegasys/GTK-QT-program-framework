#include <GQFusion/threading/CommandScheduler.h>
#include <iostream>

namespace GQFusion {

void CommandScheduler::reset() {
    commands.clear();
}

void CommandScheduler::addCommand(const std::shared_ptr<DrawCommand>& cmd) {
    commands.push_back(cmd);
}

void CommandScheduler::execute() {
    std::cout << "[CommandScheduler] Executing " 
              << commands.size() << " commands\n";

    for (auto& cmd : commands) {
        (void)cmd;
    }

    commands.clear();
}

} // namespace GQFusion
