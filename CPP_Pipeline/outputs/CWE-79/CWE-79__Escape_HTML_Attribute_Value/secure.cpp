std::string escapeHtmlAttribute(const std::string& input) {
    std::string output;
    output.reserve(input.length());
    
    for (char c : input) {
        switch (c) {
            case '"':
                output.append("&quot;");
                break;
            case '\'':
                output.append("&#39;");
                break;
            case '<':
                output.append("&lt;");
                break;
            case '>':
                output.append("&gt;");
                break;
            case '&':
                output.append("&amp;");
                break;
            default:
                output.push_back(c);
                break;
        }
    }
    
    return output;
}