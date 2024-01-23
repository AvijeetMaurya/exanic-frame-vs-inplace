#pragma once

#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <numeric>
#include <vector>

struct Stats {
    int64_t index;
    ssize_t sz;
    int64_t exanic_timestamp;
    int64_t system_timestamp;
    uint16_t stream_id;
    uint32_t sequence_no;
};

void dump_csv(std::vector<Stats>& stats, const char* filename) {
    std::ofstream csv(filename);
    csv << "index,size,exanic_timestamp,system_timestamp,stream_id,sequence_no\n";
    for (auto& stat : stats) {
        csv << stat.index << ',' << stat.sz << ',' << stat.exanic_timestamp << ',' << stat.system_timestamp << ',' << stat.stream_id << ',' << stat.sequence_no << '\n';
    }
    std::cout << "Finished dumping " << filename << '\n';
}