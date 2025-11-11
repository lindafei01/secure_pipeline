public static boolean isBinaryString(String s) {
    if (s == null || s.isEmpty()) {
        return false;
    }
    for (char c : s.toCharArray()) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}