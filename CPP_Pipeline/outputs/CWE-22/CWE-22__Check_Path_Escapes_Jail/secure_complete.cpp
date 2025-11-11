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

bool pathEscapesJail(const std::string& path, int maxDepth) {
    int depth = 0;
    size_t pos = 0;

    while (pos < path.size()) {
        size_t nextSlash = path.find('/', pos);
        std::string component = path.substr(pos, nextSlash - pos);

        if (component == "..") {
            depth--;
            if (depth < 0) {
                return true;
            }
        } else if (!component.empty() && component != ".") {
            depth++;
        }

        if (nextSlash == std::string::npos) {
            break;
        }
        pos = nextSlash + 1;
    }

    return depth > maxDepth;
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
        std::cout << "Usage: <program> path maxDepth\n";
        return 64;
    }
    std::string path_value = args[0];
    const std::string& path = path_value;
    auto maxDepth_value = std::stoi(args[1]);
    int maxDepth = static_cast<int>(maxDepth_value);
    auto result = pathEscapesJail(path, maxDepth);
    std::cout << format_output(result) << std::endl;
    return 0;
}
