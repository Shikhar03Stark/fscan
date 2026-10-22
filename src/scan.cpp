//
// Created by Harshit Vishwakarma on 22/10/26.
//

#include "fscan/scan.h"

#include <iostream>
#include <ostream>

namespace fscan {
    std::vector<std::filesystem::path> Scanner::scan(const std::filesystem::path &root) {
        std::vector<std::filesystem::path> result;
        std::error_code ec{};
        for (const auto& file : std::filesystem::directory_iterator(root, ec)) {
            if (ec) {
                std::cerr << "error: code:" << ec.value() << " " << ec.message() << std::endl;
                return result;
            }
            result.push_back(file.path());
        }
        if (ec) {
            std::cerr << "error: code:" << ec.value() << " " << ec.message() << std::endl;
        }
        return result;
    }
}
