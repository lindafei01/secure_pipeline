#include <string>
#include <vector>
#include <sstream>
#include <arpa/inet.h>

bool isIPInRanges(const std::string& ipStr, const std::vector<std::string>& ipRanges) {
    struct in_addr ip;
    if (inet_pton(AF_INET, ipStr.c_str(), &ip) != 1) {
        return false;
    }

    for (const std::string& range : ipRanges) {
        std::string ipPrefix;
        size_t prefixLength;
        
        size_t slashPos = range.find('/');
        if (slashPos == std::string::npos || 
            slashPos == 0 || 
            slashPos == range.length() - 1) {
            continue;
        }
        
        ipPrefix = range.substr(0, slashPos);
        std::istringstream(range.substr(slashPos + 1)) >> prefixLength;

        struct in_addr netAddr;
        if (inet_pton(AF_INET, ipPrefix.c_str(), &netAddr) != 1) {
            continue;
        }
        
        uint32_t mask = htonl(~((1 << (32 - prefixLength)) - 1));
        if ((ip.s_addr & mask) == (netAddr.s_addr & mask)) {
            return true;
        }
    }
    
    return false;
}