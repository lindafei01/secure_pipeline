int parseCSVInt(const std::string& line, int index) {
    size_t start = 0;
    size_t end = line.find(',');
    int currentIdx = 0;
    
    while (end != std::string::npos) {
        if (currentIdx == index) {
            return std::stoi(line.substr(start, end - start));
        }
        start = end + 1;
        end = line.find(',', start);
        currentIdx++;
    }
    
    if (currentIdx == index) {
        return std::stoi(line.substr(start));
    }
    
    return 0;
}