public static boolean isHexString(String s) {
    if (s == null || s.isEmpty()) {
        return false;
    }
    for (int i = 0; i < s.length(); i++) {
        char c = s.charAt(i);
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) {
            return false;
        }
    }
    return true;
}