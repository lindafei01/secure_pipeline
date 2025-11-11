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

std::string escapeHtml(const std::string& input) {
    std::string output = input;
    size_t pos;

    pos = output.find('<');
    while (pos != std::string::npos) {
        output.replace(pos, 1, "&lt;");
        pos = output.find('<', pos + 1);
    }

    pos = output.find('>');
    while (pos != std::string::npos) {
        output.replace(pos, 1, "&gt;");
        pos = output.find('>', pos + 1);
    }

    pos = output.find('&');
    while (pos != std::string::npos) {
        output.replace(pos, 1, "&amp;");
        pos = output.find('&', pos + 1);
    }

    pos = output.find('"');
    while (pos != std::string::npos) {
        output.replace(pos, 1, "&quot;");
        pos = output.find('"', pos + 1);
    }

    pos = output.find('\'');
    while (pos != std::string::npos) {
        output.replace(pos, 1, "&#39;");
        pos = output.find('\'', pos + 1);
    }

    return output;
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
    auto result = escapeHtml(input);
    std::cout << format_output(result) << std::endl;
    return 0;
}
