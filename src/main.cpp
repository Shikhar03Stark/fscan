#include <iostream>
#include "fscan/scan.h"

int main() {
    for (const auto result = fscan::Scanner::scan(std::filesystem::path(".")); const auto& file : result) {
        std::cout << file << std::endl;
    }
}