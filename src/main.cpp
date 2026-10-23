#include <iostream>
#include "fscan/scan.h"

int main() {
    fscan::ScannerOptions opts {
        .roots = {"."},
        .filter = {".txt"},
    };
    for (const auto result = fscan::Scanner::scan(opts); const auto& file : result) {
        std::cout << file << std::endl;
    }
}