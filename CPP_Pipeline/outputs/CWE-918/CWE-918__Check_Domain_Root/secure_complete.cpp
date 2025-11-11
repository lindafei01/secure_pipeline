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

bool matchesRootDomain(const std::string& hostname, const std::string& rootDomain) {
    if (rootDomain.empty() || hostname.empty()) return false;

    size_t lastDotPos = hostname.rfind('.');
    if (lastDotPos == std::string::npos) return false;

    size_t secondLastDotPos = hostname.rfind('.', lastDotPos - 1);
    if (secondLastDotPos == std::string::npos) return false;

    std::string extractedRootDomain = hostname.substr(secondLastDotPos + 1);

    std::transform(extractedRootDomain.begin(), extractedRootDomain.end(), extractedRootDomain.begin(), ::tolower);
    std::string lowerRootDomain = rootDomain;
    std::transform(lowerRootDomain.begin(), lowerRootDomain.end(), lowerRootDomain.begin(), ::tolower);

    return extractedRootDomain == lowerRootDomain;
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
        std::cout << "Usage: <program> hostname rootDomain\n";
        return 64;
    }
    std::string hostname_value = args[0];
    const std::string& hostname = hostname_value;
    std::string rootDomain_value = args[1];
    const std::string& rootDomain = rootDomain_value;
    auto result = matchesRootDomain(hostname, rootDomain);
    std::cout << format_output(result) << std::endl;
    return 0;
}
