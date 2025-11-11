#include <iostream>
#include <string>
#include <vector>
#include <type_traits>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <limits>
#include <sstream>
#include <regex>
#include <stdexcept>

std::string getEmailDomain(const std::string& mailAddress) {
    size_t atPosition = mailAddress.find('@');

    // Early return for missing '@' or ending with '@'
    if (atPosition == std::string::npos || atPosition == mailAddress.length() - 1) {
        return "";
    }

    // Extract domain part and validate further
    std::string domain = mailAddress.substr(atPosition + 1);

    // Check for presence of invalid characters and validate domain structure
    if (domain.find_first_of(" \t\n\r\"'<>()[]") != std::string::npos || domain.find('.') == std::string::npos) {
        return "";
    }

    return domain;
}

std::string format_output(const std::string& value) {
    return value;
}

template <typename T>
std::string format_output(const T& value) {
    if constexpr (std::is_same_v<T, bool>) {
        return value ? "true" : "false";
    }
    if constexpr (std::is_arithmetic_v<T>) {
        return std::to_string(value);
    }
    return value;
}

std::string format_output(const char* value) {
    if (value == nullptr) {
        return "null";
    }
    return std::string(value);
}

std::string format_output(std::nullptr_t) {
    return "null";
}

int main(int argc, char* argv[]) {
    std::vector<std::string> args(argv + 1, argv + argc);
    if (args.size() < 1) {
        std::cout << "Usage: <program> mailAddress\n";
        return 64;
    }
    std::string mailAddress_value = args[0];
    const std::string& mailAddress = mailAddress_value;
    auto result = getEmailDomain(mailAddress);
    std::cout << format_output(result) << std::endl;
    return 0;
}
