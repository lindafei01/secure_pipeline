int safeStoi(const std::string& inputStr) {
    try {
        return std::stoi(inputStr);
    } catch (...) {
        return 0;
    }
}