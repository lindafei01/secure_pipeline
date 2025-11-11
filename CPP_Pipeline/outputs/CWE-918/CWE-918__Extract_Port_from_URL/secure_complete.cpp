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
    std::size_t scheme_pos = url.find("://");
    if (scheme_pos == std::string::npos) return -1;

    std::string scheme = url.substr(0, scheme_pos);
    int default_port = (scheme == "http") ? 80 : (scheme == "https") ? 443 : -1;

    std::size_t host_start = scheme_pos + 3;
    std::size_t port_pos = url.find(':', host_start);
    std::size_t path_pos = url.find('/', host_start);

    if (port_pos != std::string::npos && (port_pos < path_pos || path_pos == std::string::npos)) {
        std::size_t port_end = (path_pos != std::string::npos) ? path_pos : url.length();
        std::string port_str = url.substr(port_pos + 1, port_end - port_pos - 1);

        for (char c : port_str) {
            if (!isdigit(c)) return -1; // Non-numeric port
        }

        int port = std::stoi(port_str);
        return port >= 0 && port <= 65535 ? port : -1; // Valid port range check
    }

    return default_port;
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
