public static String safeSubstring(String s, int start, int len) {
    if (s == null || start < 0 || len < 0 || start > s.length() || start + len > s.length()) {
        return null;
    }
    return s.substring(start, start + len);
}