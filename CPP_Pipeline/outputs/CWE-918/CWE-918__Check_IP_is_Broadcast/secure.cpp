bool isIPBroadcast(const std::string& ipStr) {
    if (ipStr.length() != 15) {
        return false;
    }
    return ipStr == "255.255.255.255";
}