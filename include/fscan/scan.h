//
// Created by Harshit Vishwakarma on 22/10/26.
//

#ifndef FSCAN_SCAN_H
#define FSCAN_SCAN_H
#include <filesystem>
#include <string>
#include <vector>

namespace fscan {

    struct ScannerOptions {
        std::vector<std::filesystem::path> roots{"."};
        std::string filter{};
        std::int32_t maxResults{0};
        bool recursive{false};
    };

    std::vector<std::filesystem::path> scan(const ScannerOptions& options);
}

#endif //FSCAN_SCAN_H
