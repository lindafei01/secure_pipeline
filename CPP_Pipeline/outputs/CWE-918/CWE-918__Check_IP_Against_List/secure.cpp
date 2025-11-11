bool isIPInList(const std::string& ipStr, const std::vector<std::string>& ipList) {
    if (ipStr.empty()) return false;
    
    for (const auto& ip : ipList) {
        if (ip == ipStr) {
            return true;
        }
    }
    return false;
}