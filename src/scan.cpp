//
// Created by Harshit Vishwakarma on 22/10/26.
//

#include "fscan/scan.h"

#include <iostream>

#include "fscan/error.h"

namespace fscan {

    // utils
    namespace {
        void logError(const char *functionName, const FScanException& e) {
            std::cerr << functionName << ": " << e.what() << std::endl;
        }

        void validateScannerOptions(const ScannerOptions& options) {
            if (options.roots.empty()) {
                throw FScanException("roots cannot be empty");
            }
        }
    }

    std::vector<std::filesystem::path> scan(const ScannerOptions &options) {
        try {
            validateScannerOptions(options);
            std::vector<std::filesystem::path> results;
            const bool noFilter = options.filter.empty() || options.filter == "*";
            for (const auto& root : options.roots) {
                std::error_code ec{};
                const auto addIfMatching = [&](const std::filesystem::directory_entry& entry) {
                    if (results.size() == options.maxResults && options.maxResults != 0) {
                        return;
                    }
                    std::error_code typeError{};
                    if (entry.is_regular_file(typeError) && !typeError &&
                        (noFilter || entry.path().filename().string().contains(options.filter))) {
                        results.push_back(entry.path());
                    }
                };

                if (options.recursive) {
                    std::filesystem::recursive_directory_iterator it(root, ec);
                    const std::filesystem::recursive_directory_iterator end;
                    while (!ec && it != end && (options.maxResults == 0 || results.size() < options.maxResults)) {
                        addIfMatching(*it);
                        it.increment(ec);
                    }
                } else {
                    std::filesystem::directory_iterator it(root, ec);
                    const std::filesystem::directory_iterator end;
                    while (!ec && it != end && (options.maxResults == 0 || results.size() < options.maxResults)) {
                        addIfMatching(*it);
                        it.increment(ec);
                    }
                }
            }

            return results;

        } catch (FScanException& e) {
            logError(__func__, e);
        }
        return {};
    }
}
