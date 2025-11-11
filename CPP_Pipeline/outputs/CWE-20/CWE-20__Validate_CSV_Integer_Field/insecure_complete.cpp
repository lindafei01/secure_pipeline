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

int parseCSVInt(const std::string& line, int index) {
    size_t start = 0;
    size_t end = line.find(',');
    int currentIdx = 0;

    while (end != std::string::npos) {
        if (currentIdx == index) {
            return std::stoi(line.substr(start, end - start));
        }
        start = end + 1;
        end = line.find(',', start);
        currentIdx++;
    }

    if (currentIdx == index) {
        return std::stoi(line.substr(start));
    }

    return 0;
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
        std::cout << "Usage: <program> line index\n";
        return 64;
    }
    std::string line_value = args[0];
    const std::string& line = line_value;
    auto index_value = std::stoi(args[1]);
    int index = static_cast<int>(index_value);
    auto result = parseCSVInt(line, index);
    std::cout << format_output(result) << std::endl;
    return 0;
}
