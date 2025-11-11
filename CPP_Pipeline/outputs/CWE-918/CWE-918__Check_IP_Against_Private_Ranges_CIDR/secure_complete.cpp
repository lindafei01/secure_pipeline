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

const std::vector<std::string> ipRanges = {"10.0.0.0/8", "172.16.0.0/12", "192.168.0.0/16"};

#include <string>
#include <vector>
#include <sstream>
#include <arpa/inet.h>

bool isIPInRanges(const std::string& ipStr, const std::vector<std::string>& ipRanges) {
    struct in_addr ip;
    if (inet_pton(AF_INET, ipStr.c_str(), &ip) != 1) {
        return false;
    }

    for (const std::string& range : ipRanges) {
        std::string ipPrefix;
        size_t prefixLength;

        size_t slashPos = range.find('/');
        if (slashPos == std::string::npos ||
            slashPos == 0 ||
            slashPos == range.length() - 1) {
            continue;
        }

        ipPrefix = range.substr(0, slashPos);
        std::istringstream(range.substr(slashPos + 1)) >> prefixLength;

        struct in_addr netAddr;
        if (inet_pton(AF_INET, ipPrefix.c_str(), &netAddr) != 1) {
            continue;
        }

        uint32_t mask = htonl(~((1 << (32 - prefixLength)) - 1));
        if ((ip.s_addr & mask) == (netAddr.s_addr & mask)) {
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
        std::cout << "Usage: <program> ipStr\n";
        return 64;
    }
    std::string ipStr_value = args[0];
    const std::string& ipStr = ipStr_value;
    auto result = isIPInRanges(ipStr, ::ipRanges);
    std::cout << format_output(result) << std::endl;
    return 0;
}
