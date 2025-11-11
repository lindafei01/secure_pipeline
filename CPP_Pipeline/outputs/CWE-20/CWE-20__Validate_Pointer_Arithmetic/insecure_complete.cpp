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
#include <cstddef>

bool isSafePointerArithmetic(const char* ptr, size_t offset, size_t bufferSize) {
    if (ptr == nullptr || offset > bufferSize)
        return false;
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
    if (args.size() < 3) {
        std::cout << "Usage: <program> ptr offset bufferSize\n";
        return 64;
    }
    auto& ptr_holder = args[0];
    const char* ptr = ptr_holder.c_str();
    auto offset_value = std::stoull(args[1]);
    size_t offset = static_cast<size_t>(offset_value);
    auto bufferSize_value = std::stoull(args[2]);
    size_t bufferSize = static_cast<size_t>(bufferSize_value);
    auto result = isSafePointerArithmetic(ptr, offset, bufferSize);
    std::cout << format_output(result) << std::endl;
    return 0;
}
