public static boolean endsWith(String s, String suffix) {
    if (s == null || suffix == null) {
        return false;
    }
    return s.endsWith(suffix);
}