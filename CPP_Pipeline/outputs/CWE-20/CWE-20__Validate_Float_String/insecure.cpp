bool isValidFloat(const std::string& s) {
    char* end;
    strtod(s.c_str(), &end);
    return end != s.c_str();
}