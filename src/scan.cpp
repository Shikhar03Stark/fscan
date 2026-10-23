//
// Created by Harshit Vishwakarma on 22/10/26.
//

#include "fscan/scan.h"

#include <iostream>
#include <ostream>
#include <ranges>

#include "fscan/error.h"

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

    void logError(const char *functionName, const FScanException& e) {
        std::cerr << functionName << ": " << e.what() << std::endl;
    }

    void validateScannerOptions(const ScannerOptions& options) {
        if (options.roots.empty()) {
            throw FScanException("roots cannot be empty");
        }
    }

    bool hasSubString(const std::string &s, const std::string &sub) {
        if (sub.empty()) { return true; }
        if (sub.size() > s.size()) { return false; }

        for (int i = 0; i < s.size(); i++) {
            bool isMatch{true};
            for (int j = 0; j < sub.size() && i + j < s.size(); j++) {
                if (s[i+j] != sub[j]) {
                    isMatch = false;
                }
            }
            if (isMatch) {
                return true;
            }
        }

        return false;
    }

    std::vector<std::filesystem::path> Scanner::scan(const ScannerOptions &options) {
        try {
            validateScannerOptions(options);
            std::filesystem::path firstRoot{options.roots.front()};
            auto results = scan(firstRoot);
            if (options.filter.empty() || options.filter == "*") {
                return results;
            }

            // filter
            for (int i = 0; i<results.size(); ) {
                if (!hasSubString(results[i], options.filter)) {
                    std::swap(results[i], results.back());
                    results.pop_back();
                }
                else {
                    i++;
                }
            }

            return results;

        } catch (FScanException& e) {
            logError(__func__, e);
        }
        return {};
    }
}
