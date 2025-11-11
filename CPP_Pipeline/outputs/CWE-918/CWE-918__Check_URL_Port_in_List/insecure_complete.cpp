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

const std::vector<int> allowedPorts = {80, 443, 8080};

bool isURLPortAllowed(const std::string& url, const std::vector<int>& allowedPorts) {
    size_t scheme_end = url.find("://");
    size_t start = (scheme_end == std::string::npos) ? 0 : scheme_end + 3;
    size_t port_start = url.find(':', start);
    size_t path_start = url.find('/', start);

    if (port_start == std::string::npos || port_start > path_start) {
        port_start = path_start;
    }

    std::string scheme = (scheme_end == std::string::npos) ? "" : url.substr(0, scheme_end);
    int port = (scheme == "https") ? 443 : 80;

    if (port_start != std::string::npos && port_start != path_start) {
        size_t port_end = url.find('/', port_start);
        std::string port_str = url.substr(port_start + 1, port_end - port_start - 1);
        port = std::stoi(port_str);
    }

    return std::find(allowedPorts.begin(), allowedPorts.end(), port) != allowedPorts.end();
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
    auto result = isURLPortAllowed(url, ::allowedPorts);
    std::cout << format_output(result) << std::endl;
    return 0;
}
