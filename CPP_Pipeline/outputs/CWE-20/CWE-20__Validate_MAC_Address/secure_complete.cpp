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

bool isValidMAC(const std::string& mac) {
    if (mac.length() != 17) {
        return false;
    }
    for (size_t i = 0; i < mac.length(); ++i) {
        if (i % 3 == 2) {
            if (mac[i] != ':') {
                return false;
            }
        } else {
            if (!((mac[i] >= '0' && mac[i] <= '9') || (mac[i] >= 'A' && mac[i] <= 'F') || (mac[i] >= 'a' && mac[i] <= 'f'))) {
                return false;
            }
        }
    }
    return true;
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
        std::cout << "Usage: <program> mac\n";
        return 64;
    }
    std::string mac_value = args[0];
    const std::string& mac = mac_value;
    auto result = isValidMAC(mac);
    std::cout << format_output(result) << std::endl;
    return 0;
}
