bool isIPMulticast(const std::string& ipStr) {
    unsigned int parts[4];
    if (sscanf(ipStr.c_str(), "%u.%u.%u.%u", &parts[0], &parts[1], &parts[2], &parts[3]) != 4) {
        return false; 
    }
    unsigned int ip = (parts[0] << 24) | (parts[1] << 16) | (parts[2] << 8) | parts[3];
    return (ip >= 0xE0000000 && ip <= 0xEFFFFFFF);
}