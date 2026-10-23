//
// Created by Harshit Vishwakarma on 24/10/26.
//

#ifndef FSCAN_ERROR_H
#define FSCAN_ERROR_H
#include <exception>
#include <string>

namespace fscan {
    class FScanException : public std::exception {
        std::string _message;
    public:
        explicit FScanException(std::string  message);

        [[nodiscard]] const char * what() const noexcept override;
    };
}

#endif //FSCAN_ERROR_H
