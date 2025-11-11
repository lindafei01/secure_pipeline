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

bool isURLHostnameNotIP(const std::string& url) {
    std::string::const_iterator it = url.begin();

    // Find "://" to isolate the hostname
    std::string::size_type pos = url.find("://");
    if (pos == std::string::npos) return false;  // Invalid URL format
    std::advance(it, pos + 3);

    // Extract the hostname portion
    std::string::size_type host_end = url.find_first_of(":/", pos + 3);
    std::string hostname = url.substr(pos + 3, host_end - pos - 3);

    // Check if the hostname is an IP address using digit-only segments
    int segments = 0;
    bool valid_ip = true;
    std::string::size_type start = 0;

    while (start < hostname.length()) {
        std::string::size_type dot_pos = hostname.find('.', start);
        if (dot_pos == std::string::npos) dot_pos = hostname.length();
        std::string segment = hostname.substr(start, dot_pos - start);

        if (segment.empty() || segment.length() > 3 ||
            !std::all_of(segment.begin(), segment.end(), ::isdigit) ||
            std::stoi(segment) > 255) {
            valid_ip = false;
            break;
        }

        segments++;
        start = dot_pos + 1;
    }

    if (segments != 4) valid_ip = false;

    return !valid_ip;
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
    auto result = isURLHostnameNotIP(url);
    std::cout << format_output(result) << std::endl;
    return 0;
}
