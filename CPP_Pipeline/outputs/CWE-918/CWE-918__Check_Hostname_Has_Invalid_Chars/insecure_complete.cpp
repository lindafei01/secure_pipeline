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

bool hostnameHasInvalidChars(const std::string& hostname, const std::string& invalidChars) {
    for (char c : hostname) {
        if (invalidChars.find(c) != std::string::npos) {
            return true;
        }
    }
    size_t pos = hostname.find(":"); // Check if it's likely a URL
    if (pos != std::string::npos) {
        std::string hostPart = hostname.substr(0, pos + 3);
        if (hostPart == "http://" || hostPart == "https://") {
            return true; // Prevent usage of URLs based on CWE-918
        }
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
    if (args.size() < 2) {
        std::cout << "Usage: <program> hostname invalidChars\n";
        return 64;
    }
    std::string hostname_value = args[0];
    const std::string& hostname = hostname_value;
    std::string invalidChars_value = args[1];
    const std::string& invalidChars = invalidChars_value;
    auto result = hostnameHasInvalidChars(hostname, invalidChars);
    std::cout << format_output(result) << std::endl;
    return 0;
}
