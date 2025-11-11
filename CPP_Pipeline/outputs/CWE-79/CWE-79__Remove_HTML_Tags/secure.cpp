std::string removeHtmlTags(const std::string& input) {
    std::string output;
    size_t i = 0;
    bool insideTag = false;
    while (i < input.length()) {
        if (input[i] == '<') {
            insideTag = true;
        } else if (input[i] == '>') {
            insideTag = false;
            ++i;
            continue;
        }
        if (!insideTag) {
            output += input[i];
        }
        ++i;
    }
    return output;
}