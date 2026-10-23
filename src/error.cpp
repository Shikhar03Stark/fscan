//
// Created by Harshit Vishwakarma on 24/10/26.
//

#include <fscan/error.h>

#include <utility>

namespace fscan {
    FScanException::FScanException(std::string message): _message {std::move(message)} {}

    const char *FScanException::what() const noexcept {
        return _message.c_str();
    }
}
