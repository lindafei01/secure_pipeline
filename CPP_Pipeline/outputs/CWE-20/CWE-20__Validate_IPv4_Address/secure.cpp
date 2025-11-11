bool isValidIPv4(const std::string& ipStr) {
    if (ipStr.empty() || ipStr.size() < 7 || ipStr.size() > 15) return false;
    int count = 0;
    size_t start = 0, end;
    while ((end = ipStr.find('.', start)) != std::string::npos || start < ipStr.size()) {
        std::string octet = ipStr.substr(start, end - start);
        if (octet.empty() || octet.size() > 3) return false;
        for (char c : octet) {
            if (!isdigit(c)) return false;
        }
        int num = stoi(octet);
        if (num < 0 || num > 255) return false;
        count++;
        if (end == std::string::npos) break;
        start = end + 1;
    }
    return count == 4;
}