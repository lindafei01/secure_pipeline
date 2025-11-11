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

#include <string>
#include <regex>
#include <cstdint>
#include <sstream>
#include <netdb.h>
#include <arpa/inet.h>

bool isValidWebhookURL(const std::string& webhookURL) {
    // Check if URL starts with "https://"
    const std::string httpsPrefix = "https://";
    if (webhookURL.substr(0, httpsPrefix.size()) != httpsPrefix) {
        return false;
    }

    // Extract the hostname
    std::string host = webhookURL.substr(httpsPrefix.size());
    size_t pos = host.find('/');
    if (pos != std::string::npos) {
        host = host.substr(0, pos);
    }

    // Check if the host is a valid IP address
    struct sockaddr_in sa;
    struct sockaddr_in6 sa6;
    if (inet_pton(AF_INET, host.c_str(), &(sa.sin_addr)) != 0 ||
        inet_pton(AF_INET6, host.c_str(), &(sa6.sin6_addr)) != 0) {
        return false; // Hostname is a literal IP address
    }

    // Last check: ensure the hostname resolves through DNS lookup
    struct addrinfo hints, *info;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC; // Allow IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host.c_str(), nullptr, &hints, &info) != 0) {
        return false; // Cannot resolve the hostname
    }

    freeaddrinfo(info);
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
        std::cout << "Usage: <program> webhookURL\n";
        return 64;
    }
    std::string webhookURL_value = args[0];
    const std::string& webhookURL = webhookURL_value;
    auto result = isValidWebhookURL(webhookURL);
    std::cout << format_output(result) << std::endl;
    return 0;
}
