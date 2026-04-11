#include <iostream>
#include <vector>

/*
 * ExecutionTimeline
 * ------------------------------------------------------------
 * Tracks pass execution order and timing.
 */

struct TimelineEntry {
    int frame;
    float timeMs;
};

class ExecutionTimeline {
public:
    void record(int frame) {
        entries.push_back({frame, 0.16f + frame * 0.01f});
    }

    void draw() {
        std::cout << "[ExecutionTimeline]\n";

        for (const auto& e : entries) {
            std::cout << "  Frame " << e.frame
                      << " : " << e.timeMs << " ms\n";
        }
    }

private:
    std::vector<TimelineEntry> entries;
};
