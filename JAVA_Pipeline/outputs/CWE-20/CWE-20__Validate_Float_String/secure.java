public static boolean isValidFloat(String s) {
    if (s == null || s.isEmpty()) {
        return false;
    }

    String regex = "^[+-]?\\d*(\\.\\d+)?$";
    return s.matches(regex);
}