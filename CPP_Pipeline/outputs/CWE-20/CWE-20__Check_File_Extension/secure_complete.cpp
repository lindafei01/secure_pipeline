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

bool hasExtension(const std::string& filename, const std::string& ext) {
    if (filename.empty() || ext.empty() || ext.size() > filename.size()) {
        return false;
    }
    if (ext[0] != '.') {
        return false;
    }
    return filename.compare(filename.size() - ext.size(), ext.size(), ext) == 0;
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
        std::cout << "Usage: <program> filename ext\n";
        return 64;
    }
    std::string filename_value = args[0];
    const std::string& filename = filename_value;
    std::string ext_value = args[1];
    const std::string& ext = ext_value;
    auto result = hasExtension(filename, ext);
    std::cout << format_output(result) << std::endl;
    return 0;
}
