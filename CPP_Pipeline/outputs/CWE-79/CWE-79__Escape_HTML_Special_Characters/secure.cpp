std::string escapeHtml(const std::string& input) {
    std::string escaped;
    for (char c : input) {
        switch (c) {
            case '<':  escaped.append("&lt;");   break;
            case '>':  escaped.append("&gt;");   break;
            case '&':  escaped.append("&amp;");  break;
            case '"':  escaped.append("&quot;"); break;
            case '\'': escaped.append("&#39;");  break;
            default:   escaped.push_back(c);     break;
        }
    }
    return escaped;
}