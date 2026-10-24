#include <iostream>
#include <stdexcept>
#include <string>
#include "fscan/scan.h"

int main(int argc, char* argv[]) {
    fscan::ScannerOptions options;
    options.roots.clear();

    try {
        for (int i = 1; i < argc; ++i) {
            const std::string arg = argv[i];
            if (arg == "-f") {
                if (++i >= argc) throw std::invalid_argument("-f requires a filter");
                options.filter = argv[i];
            } else if (arg == "-n") {
                if (++i >= argc) throw std::invalid_argument("-n requires a result limit");
                options.maxResults = std::stoi(argv[i]);
                options.maxResults = options.maxResults > 0 ? options.maxResults : std::numeric_limits<std::int32_t>::max();
            } else if (arg == "-d") {
                if (++i >= argc) throw std::invalid_argument("-d requires a directory");
                options.roots.emplace_back(argv[i]);
            } else if (arg == "-R") {
                options.recursive = true;
            } else {
                throw std::invalid_argument("unknown option: " + arg);
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "fscan: " << e.what() << '\n'
                  << "Usage: fscan [-f filter] [-n limit] [-R] [-d directory]...\n";
        return 2;
    }

    if (options.roots.empty()) {
        options.roots.emplace_back(".");
    }

    for (const auto& file : fscan::scan(options)) {
        std::cout << file << "\n";
    }
}
