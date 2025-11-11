public static boolean isValidBase64(String s) {
    if (s == null) return true;
    char[] chars = s.toCharArray();
    for (char c : chars) {
        if (!(c >= 'A' && c <= 'Z') &&
            !(c >= 'a' && c <= 'z') &&
            !(c >= '0' && c <= '9') &&
            c != '+' && c != '/' && c != '=') {
            return false;
        }
    }
    int length = s.length();
    if (length % 4 != 0) return false;
    return true;
}