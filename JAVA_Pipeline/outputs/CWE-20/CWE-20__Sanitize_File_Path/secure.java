public static boolean isSafePath(String pathStr) {
    if (pathStr == null) {
        return false;
    }
    if (pathStr.contains("..")) {
        return false;
    }
    for (char ch : pathStr.toCharArray()) {
        if (ch == '\0' || ch == '/' || ch == '\\' || ch == '?' || ch == '*' || ch == ':' || ch == '|' || ch == '<' || ch == '>') {
            return false;
        }
    }
    return true;
}