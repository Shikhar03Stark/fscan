//
// Created by Harshit Vishwakarma on 22/10/26.
//

#ifndef FSCAN_SCAN_H
#define FSCAN_SCAN_H
#include <filesystem>
#include <vector>

namespace fscan {
    class Scanner {
    public:
        static std::vector<std::filesystem::path> scan(const std::filesystem::path& root);
    };
}

#endif //FSCAN_SCAN_H
