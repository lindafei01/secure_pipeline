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

bool isIPMulticast(const std::string& ipStr) {
    size_t pos = 0;
    int parts[4] = {0};

    for (int i = 0; i < 4; ++i) {
        size_t nextPos = ipStr.find('.', pos);
        if (nextPos == std::string::npos && i < 3) {
            return false;
        }

        std::string partStr = ipStr.substr(pos, nextPos - pos);
        if (partStr.empty() || partStr.length() > 3) {
            return false;
        }

        int part = 0;
        for (char c : partStr) {
            if (!isdigit(c)) {
                return false;
            }
            part = part * 10 + (c - '0');
            if (part > 255) {
                return false;
            }
        }

        parts[i] = part;
        pos = nextPos + 1;
    }

    if (pos != std::string::npos + 1) {
        return false; // Handle any extra invalid characters after parsing all 4 parts.
    }

    if (parts[0] >= 224 && parts[0] <= 239) {
        return true;
    }

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
        std::cout << "Usage: <program> ipStr\n";
        return 64;
    }
    std::string ipStr_value = args[0];
    const std::string& ipStr = ipStr_value;
    auto result = isIPMulticast(ipStr);
    std::cout << format_output(result) << std::endl;
    return 0;
}
