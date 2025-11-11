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
#include <set>

const std::vector<std::string> xssBlocklist = {"<script", "javascript:", "onerror=", "onload="};

bool validateAgainstXssBlocklist(const std::string& input, const std::vector<std::string>& blocklist) {
    std::string inputLower;
    inputLower.reserve(input.size());
    for (char ch : input) {
        inputLower.push_back(std::tolower(static_cast<unsigned char>(ch)));
    }
    for (const std::string& pattern : blocklist) {
        std::string patternLower;
        patternLower.reserve(pattern.size());
        for (char ch : pattern) {
            patternLower.push_back(std::tolower(static_cast<unsigned char>(ch)));
        }
        if (inputLower.find(patternLower) != std::string::npos) {
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
        std::cout << "Usage: <program> input\n";
        return 64;
    }
    std::string input_value = args[0];
    const std::string& input = input_value;
    auto result = validateAgainstXssBlocklist(input, ::xssBlocklist);
    std::cout << format_output(result) << std::endl;
    return 0;
}
