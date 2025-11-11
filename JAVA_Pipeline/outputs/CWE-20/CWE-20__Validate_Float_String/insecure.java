public static boolean isValidFloat(String s) {
    if (s == null) return false;
    return s.matches("[-+]?\\d*\\.\\d+");
}