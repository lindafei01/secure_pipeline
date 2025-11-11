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

bool containsEventHandlers(const std::string& input) {
    std::string lowerInput = input;
    std::transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);
    const std::vector<std::string> eventHandlers = {
        "onclick", "onload", "onerror", "onmouseover", "onfocus",
        "onblur", "onkeydown", "onkeyup", "onsubmit", "onreset",
        "onchange", "onselect", "onabort", "onbeforeunload",
        "onhashchange", "oninput", "oninvalid", "onredo", "onresize",
        "onscroll", "onsearch", "onseeked", "onseek", "onseeked",
        "ontoggle", "onunload", "onwheel", "ondrag", "ondrop",
        "oncopy", "oncut", "onpaste", "oncontextmenu", "onauxclick",
        "ondblclick", "ondragend", "ondragstart", "onmouseout",
        "onmouseup", "onplay", "onplaying", "onpause", "onvolumechange"
    };
    for (const auto& handler : eventHandlers) {
        if (lowerInput.find(handler) != std::string::npos) {
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
    auto result = containsEventHandlers(input);
    std::cout << format_output(result) << std::endl;
    return 0;
}
