bool isValidIPv4(const std::string& ipStr) {
    int parts[4];
    sscanf(ipStr.c_str(), "%d.%d.%d.%d", &parts[0], &parts[1], &parts[2], &parts[3]);
    for(int i = 0; i < 4; ++i) {
        if(parts[i] < 0 || parts[i] > 255) {
            return false;
        }
    }
    return true;
}