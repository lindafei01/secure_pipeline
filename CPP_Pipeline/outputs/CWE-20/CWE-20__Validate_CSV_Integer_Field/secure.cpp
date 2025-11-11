int parseCSVInt(const std::string& line, int index) {
    if (index < 0) {
        return 0;
    }
    
    size_t start = 0;
    size_t end = line.find(',');
    int currentIndex = 0;
    
    while (end != std::string::npos && currentIndex < index) {
        start = end + 1;
        end = line.find(',', start);
        currentIndex++;
    }
    
    if (currentIndex != index) {
        return 0;
    }
    
    std::string token = line.substr(start, end - start);
    
    try {
        size_t pos;
        int value = std::stoi(token, &pos);
        
        // Ensure whole token was parsed and it doesn't contain trailing characters
        if (pos == token.size()) {
            return value;
        }
    } catch (...) {
        // Catching all exceptions as std::stoi might throw on invalid input
    }
    
    return 0;
}