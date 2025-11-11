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

bool urlHasNoCredentials(const std::string& url) {
    std::string::size_type protocol_end = url.find("://");
    if (protocol_end == std::string::npos) {
        return true; // No protocol specified, consider no credentials
    }
    std::string::size_type start_pos = protocol_end + 3; // Skip past "://"
    std::string::size_type at_symbol_pos = url.find('@', start_pos);
    if (at_symbol_pos == std::string::npos) {
        return true; // No '@' found, no credentials present
    }
    std::string::size_type separator_pos = url.find('/', start_pos);
    if (separator_pos != std::string::npos && at_symbol_pos > separator_pos) {
        return true; // '@' found after the path, not part of credentials
    }
    return false; // '@' found before the path, indicating credentials
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
    auto result = urlHasNoCredentials(url);
    std::cout << format_output(result) << std::endl;
    return 0;
}
