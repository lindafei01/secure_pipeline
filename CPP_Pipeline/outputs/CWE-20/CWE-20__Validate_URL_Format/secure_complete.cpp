#include <iostream>
#include <string>
#include <vector>
#include <type_traits>
#include <sstream>

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

bool isValidURL(const std::string& url) {
    if (url.empty()) return false;

    const std::string httpPrefix = "http://";
    const std::string httpsPrefix = "https://";
    size_t prefixLength = 0;

    if (url.substr(0, httpPrefix.size()) == httpPrefix) {
        prefixLength = httpPrefix.size();
    } else if (url.substr(0, httpsPrefix.size()) == httpsPrefix) {
        prefixLength = httpsPrefix.size();
    } else {
        return false;
    }

    size_t domainStart = url.find_first_not_of(".:/", prefixLength);
    if (domainStart == std::string::npos || domainStart <= prefixLength)
        return false;

    size_t domainEnd = url.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-.", domainStart);
    if (domainEnd == std::string::npos || domainEnd <= domainStart)
        return true;

    return false;
}

std::string format_output(const std::string& value) {
    return value;
}

template <typename T>
std::string format_output(const T& value) {
    using Decayed = std::decay_t<T>;
    if constexpr (std::is_same_v<Decayed, bool>) {
        return value ? "true" : "false";
    }
    if constexpr (std::is_arithmetic_v<Decayed>) {
        return std::to_string(value);
    }
    if constexpr (std::is_convertible_v<Decayed, std::string>) {
        return static_cast<std::string>(value);
    }
    std::ostringstream oss;
    oss << value;
    return oss.str();
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
        std::cout << "Usage: <program> url\n";
        return 64;
    }
    std::string url_value = args[0];
    const std::string& url = url_value;
    auto result = isValidURL(url);
    std::cout << format_output(result) << std::endl;
    return 0;
}
