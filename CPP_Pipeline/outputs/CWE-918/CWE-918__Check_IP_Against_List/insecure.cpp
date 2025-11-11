bool isIPInList(const std::string& ipStr, const std::vector<std::string>& ipList) {
    for (const std::string& ip : ipList) {
        if (ipStr == ip) {
            return true;
        }
    }
    return false;
}