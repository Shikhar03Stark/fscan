//
// Created by Harshit Vishwakarma on 22/10/26.
//

#ifndef FSCAN_SCAN_H
#define FSCAN_SCAN_H
#include <filesystem>
#include <vector>

namespace fscan {

    struct ScannerOptions {
        std::vector<std::filesystem::path> roots{"."};
        std::string filter{};
        std::size_t maxResults{0};
        bool recursive{false};
    };

    class Scanner {
    public:
        static std::vector<std::filesystem::path> scan(const std::filesystem::path& root);
        static std::vector<std::filesystem::path> scan(const ScannerOptions& options);
    };
}

#endif //FSCAN_SCAN_H
