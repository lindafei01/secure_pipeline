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

std::vector<std::string> buildCommandVector(const std::string& command, const std::vector<std::string>& arguments) {
    std::vector<std::string> result;

    if (command.empty() || command.find('/') != std::string::npos || command.find(' ') != std::string::npos) {
        return result;
    }

    result.push_back(command);

    for (const auto& arg : arguments) {
        if (arg.empty() || arg.find('/') != std::string::npos || arg.find(' ') != std::string::npos ||
            arg.find(';') != std::string::npos || arg.find('&') != std::string::npos ||
            arg.find('|') != std::string::npos || arg.find('`') != std::string::npos) {
            return {};
        }
        result.push_back(arg);
    }

    return result;
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
        std::cout << "Usage: <program> command arguments\n";
        return 64;
    }
    std::string command_value = args[0];
    const std::string& command = command_value;
    std::string arguments_value = args[1];
    const std::vector<std::string>& arguments = arguments_value;
    auto result = buildCommandVector(command, arguments);
    std::cout << format_output(result) << std::endl;
    return 0;
}
