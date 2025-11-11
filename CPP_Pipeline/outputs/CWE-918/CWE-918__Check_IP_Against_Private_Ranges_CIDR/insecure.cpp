bool isIPInRanges(const std::string& ipStr, const std::vector<std::string>& ipRanges) {
    for (const auto& range : ipRanges) {
        std::string delimiter = "/";
        size_t pos = range.find(delimiter);
        std::string ipPart = range.substr(0, pos);
        int prefixLength = std::stoi(range.substr(pos + delimiter.length()));

        struct sockaddr_in sa;
        inet_pton(AF_INET, ipStr.c_str(), &(sa.sin_addr));
        unsigned long ipAddr = ntohl(sa.sin_addr.s_addr);

        inet_pton(AF_INET, ipPart.c_str(), &(sa.sin_addr));
        unsigned long rangeAddr = ntohl(sa.sin_addr.s_addr);

        unsigned long mask = (0xFFFFFFFF << (32 - prefixLength)) & 0xFFFFFFFF;
        
        if ((ipAddr & mask) == (rangeAddr & mask)) {
            return true;
        }
    }
    return false;
}