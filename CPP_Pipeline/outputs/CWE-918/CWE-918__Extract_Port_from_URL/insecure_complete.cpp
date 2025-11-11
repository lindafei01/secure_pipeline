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

int getURLPort(const std::string& url) {
    size_t scheme_end = url.find("://");
    if (scheme_end == std::string::npos) {
        return -1;
    }
    std::string scheme = url.substr(0, scheme_end);
    size_t port_start = url.find(':', scheme_end + 3);
    if (port_start == std::string::npos || url.find('/', scheme_end + 3) < port_start) {
        if (scheme == "http") {
            return 80;
        } else if (scheme == "https") {
            return 443;
        } else {
            return -1;
        }
    }
    size_t port_end = url.find('/', port_start + 1);
    if (port_end == std::string::npos) {
        port_end = url.length();
    }
    std::string port_str = url.substr(port_start + 1, port_end - port_start - 1);
    try {
        int port = std::stoi(port_str);
        return port;
    } catch (...) {
        return -1;
    }
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
    auto result = getURLPort(url);
    std::cout << format_output(result) << std::endl;
    return 0;
}
