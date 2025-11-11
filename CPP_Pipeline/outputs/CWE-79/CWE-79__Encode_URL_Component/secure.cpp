std::string encodeUrlComponent(const std::string& input) {
    const std::string unreserved = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_.~";
    std::string result;
    for (char c : input) {
        if (unreserved.find(c) != std::string::npos) {
            result += c;
        } else {
            result += '%' + std::to_string((unsigned char)c / 16);
            result.back() = (result.back() < 10 ? '0' : 'A' - 10) + result.back();
            result += std::to_string((unsigned char)c % 16);
            result.back() = (result.back() < 10 ? '0' : 'A' - 10) + result.back();
        }
    }
    return result;
}