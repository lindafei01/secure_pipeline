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

bool isHostnameLiteralIP(const std::string& hostname) {
    std::size_t length = hostname.length();
    if (length == 0) {
        return false;
    }

    // Check for IPv4
    int dotCount = 0;
    int digitCount = 0;
    for (char ch : hostname) {
        if (ch == '.') {
            dotCount++;
            if (digitCount == 0) {
                return false;
            }
            digitCount = 0;
        } else if (isdigit(ch)) {
            digitCount++;
            if (digitCount > 3) {
                return false;
            }
        } else {
            return false;
        }
    }
    if (dotCount == 3 && digitCount > 0) {
        return true;
    }

    // Check for IPv6
    if (length < 2 || hostname.front() != '[' || hostname.back() != ']') {
        return false;
    }
    std::string ipv6 = hostname.substr(1, length - 2);
    int colonCount = 0;
    dotCount = 0;
    digitCount = 0;
    bool hasDigits = false;
    for (char ch : ipv6) {
        if (ch == ':') {
            colonCount++;
            if (digitCount == 0 && !hasDigits) {
                return false;
            }
            digitCount = 0;
        } else if (ch == '.') {
            dotCount++;
            if (digitCount == 0) {
                return false;
            }
            digitCount = 0;
        } else if (isxdigit(ch) || (ch == 'a' || ch == 'A' || ch == 'b' || ch == 'B' ||
                                    ch == 'c' || ch == 'C' || ch == 'd' || ch == 'D' ||
                                    ch == 'e' || ch == 'E' || ch == 'f' || ch == 'F')) {
            hasDigits = true;
            digitCount++;
            if (digitCount > 4 && ch != '.') {
                return false;
            }
        } else {
            return false;
        }
    }
    if (colonCount >= 2 && colonCount <= 7 && dotCount <= 3) {
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
        std::cout << "Usage: <program> hostname\n";
        return 64;
    }
    std::string hostname_value = args[0];
    const std::string& hostname = hostname_value;
    auto result = isHostnameLiteralIP(hostname);
    std::cout << format_output(result) << std::endl;
    return 0;
}
