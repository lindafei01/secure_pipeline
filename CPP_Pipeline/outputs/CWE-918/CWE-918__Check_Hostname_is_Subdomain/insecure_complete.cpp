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

bool isSubdomain(const std::string& hostname, const std::string& parentDomain) {
    std::string lowerHostname = hostname;
    std::string lowerParentDomain = parentDomain;
    std::transform(lowerHostname.begin(), lowerHostname.end(), lowerHostname.begin(), ::tolower);
    std::transform(lowerParentDomain.begin(), lowerParentDomain.end(), lowerParentDomain.begin(), ::tolower);
    return lowerHostname.size() >= lowerParentDomain.size() &&
           lowerHostname.compare(lowerHostname.size() - lowerParentDomain.size(), lowerParentDomain.size(), lowerParentDomain) == 0 &&
           (lowerHostname.size() == lowerParentDomain.size() || lowerHostname[lowerHostname.size() - lowerParentDomain.size() - 1] == '.');
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
        std::cout << "Usage: <program> hostname parentDomain\n";
        return 64;
    }
    std::string hostname_value = args[0];
    const std::string& hostname = hostname_value;
    std::string parentDomain_value = args[1];
    const std::string& parentDomain = parentDomain_value;
    auto result = isSubdomain(hostname, parentDomain);
    std::cout << format_output(result) << std::endl;
    return 0;
}
