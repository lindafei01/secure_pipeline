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

const std::vector<std::string> blockedSchemes = {"file", "ftp", "gopher", "ldap"};

bool isURLSchemeBlocked(const std::string& url, const std::vector<std::string>& blockedSchemes) {
    auto start = url.find("://");
    if (start == std::string::npos) {
        return false;
    }

    std::string scheme = url.substr(0, start);
    std::transform(scheme.begin(), scheme.end(), scheme.begin(), ::tolower);

    for (const auto& blockedScheme : blockedSchemes) {
        std::string schemeLower = blockedScheme;
        std::transform(schemeLower.begin(), schemeLower.end(), schemeLower.begin(), ::tolower);

        if (scheme == schemeLower) {
            return true;
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
    if (args.size() < 1) {
        std::cout << "Usage: <program> url\n";
        return 64;
    }
    std::string url_value = args[0];
    const std::string& url = url_value;
    auto result = isURLSchemeBlocked(url, ::blockedSchemes);
    std::cout << format_output(result) << std::endl;
    return 0;
}
