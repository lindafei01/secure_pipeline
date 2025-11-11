#include <string>
#include <vector>
#include <regex>
#include <algorithm>

bool isURLPortAllowed(const std::string& url, const std::vector<int>& allowedPorts) {
    std::regex urlRegex(R"(^(https?)://([^:/\\s]+)(?::(\d+))?)");
    std::smatch match;
    
    if (!std::regex_search(url, match, urlRegex) || match.size() < 3) {
        return false; // invalid URL format
    }

    std::string scheme = match[1].str();
    std::string portStr = match[3].str();
    
    int port = 0;
    if (!portStr.empty()) {
        try {
            port = std::stoi(portStr);
        } catch (const std::exception&) {
            return false; // invalid port number
        }
    } else {
        port = (scheme == "https") ? 443 : 80; // default ports for http and https
    }

    return std::find(allowedPorts.begin(), allowedPorts.end(), port) != allowedPorts.end();
}