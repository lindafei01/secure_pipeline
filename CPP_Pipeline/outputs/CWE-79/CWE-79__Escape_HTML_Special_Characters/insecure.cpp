std::string escapeHtml(const std::string& input) {
    std::string output = input;
    size_t pos;

    pos = output.find('<');
    while (pos != std::string::npos) {
        output.replace(pos, 1, "&lt;");
        pos = output.find('<', pos + 1);
    }
    
    pos = output.find('>');
    while (pos != std::string::npos) {
        output.replace(pos, 1, "&gt;");
        pos = output.find('>', pos + 1);
    }
    
    pos = output.find('&');
    while (pos != std::string::npos) {
        output.replace(pos, 1, "&amp;");
        pos = output.find('&', pos + 1);
    }
    
    pos = output.find('"');
    while (pos != std::string::npos) {
        output.replace(pos, 1, "&quot;");
        pos = output.find('"', pos + 1);
    }
    
    pos = output.find('\'');
    while (pos != std::string::npos) {
        output.replace(pos, 1, "&#39;");
        pos = output.find('\'', pos + 1);
    }

    return output;
}