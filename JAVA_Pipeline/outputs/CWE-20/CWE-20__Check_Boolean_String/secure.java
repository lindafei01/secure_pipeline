public static Boolean parseBool(String s) {
    if (s == null) {
        return null;
    }
    String trimmedInput = s.trim().toLowerCase();
    if ("true".equals(trimmedInput)) {
        return Boolean.TRUE;
    } else if ("false".equals(trimmedInput)) {
        return Boolean.FALSE;
    } else {
        return null;
    }
}