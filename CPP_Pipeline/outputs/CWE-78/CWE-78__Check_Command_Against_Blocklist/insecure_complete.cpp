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

const std::vector<std::string> blocklist = {"rm", "dd", "mkfs", "shutdown"};

bool isCommandBlocked(const std::string& command, const std::vector<std::string>& blocklist) {
    std::string concatenatedCommands;
    for (const auto& cmd : blocklist) {
        concatenatedCommands += cmd + " ";
    }
    std::string systemCommand = "echo " + command + " | grep -w \"" + concatenatedCommands + "\"";
    int result = system(systemCommand.c_str());
    return result == 0;
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
        std::cout << "Usage: <program> command\n";
        return 64;
    }
    std::string command_value = args[0];
    const std::string& command = command_value;
    auto result = isCommandBlocked(command, ::blocklist);
    std::cout << format_output(result) << std::endl;
    return 0;
}
