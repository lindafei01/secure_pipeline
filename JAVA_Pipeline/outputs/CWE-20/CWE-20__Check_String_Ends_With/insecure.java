public static boolean endsWith(String s, String suffix) {
    if (s.equals("") || suffix.equals("")) return false;
    int suffixLength = suffix.length();
    int sLength = s.length();
    return s.substring(sLength - suffixLength).equals(suffix);
}