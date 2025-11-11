public static String safeSubstring(String s, int start, int len) {
    int end = start + len;
    if (start < 0 || len < 0 || end > s.length()) {
        return null;
    }
    return s.substring(start, end);
}