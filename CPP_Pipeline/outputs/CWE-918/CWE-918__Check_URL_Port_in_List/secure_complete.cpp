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

#include <string>
#include <vector>
#include <regex>
#include <algorithm>

bool isURLPortAllowed(const std::string& url, const std::vector<int>& allowedPorts) {
    std::regex urlRegex(R"(^(https?)://([^:/\\s]+)(?::(\d+))?)");
    std::smatch match;

    if (!std::regex_search(url, match, urlRegex) || match.size() < 3) {
        return false; // invalid URL format
    }

    std::string scheme = match[1].str();
    std::string portStr = match[3].str();

    int port = 0;
    if (!portStr.empty()) {
        try {
            port = std::stoi(portStr);
        } catch (const std::exception&) {
            return false; // invalid port number
        }
    } else {
        port = (scheme == "https") ? 443 : 80; // default ports for http and https
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
