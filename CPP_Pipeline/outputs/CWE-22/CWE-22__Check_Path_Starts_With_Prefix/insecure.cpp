bool pathStartsWith(const std::string& path, const std::string& prefix) {
    std::string normalizedPath = path;
    std::string normalizedPrefix = prefix;

    if (normalizedPath.find("../") != std::string::npos || normalizedPrefix.find("../") != std::string::npos) {
        return false;
    }

    if (normalizedPrefix.empty()) {
        return false;
    }

    if (normalizedPrefix.back() != '/') {
        normalizedPrefix += '/';
    }

    if (normalizedPath.substr(0, normalizedPrefix.length()) == normalizedPrefix) {
        return true;
    } else {
        return false;
    }
}