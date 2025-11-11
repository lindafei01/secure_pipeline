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

bool isPortInRange(int port, int minPort, int maxPort) {
    if (port < 0 || minPort < 0 || maxPort < 0) return false;
    if (port > 65535 || minPort > 65535 || maxPort > 65535) return false;
    if (minPort > maxPort) return false;
    return port >= minPort && port <= maxPort;
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
    if (args.size() < 3) {
        std::cout << "Usage: <program> port minPort maxPort\n";
        return 64;
    }
    auto port_value = std::stoi(args[0]);
    int port = static_cast<int>(port_value);
    auto minPort_value = std::stoi(args[1]);
    int minPort = static_cast<int>(minPort_value);
    auto maxPort_value = std::stoi(args[2]);
    int maxPort = static_cast<int>(maxPort_value);
    auto result = isPortInRange(port, minPort, maxPort);
    std::cout << format_output(result) << std::endl;
    return 0;
}
