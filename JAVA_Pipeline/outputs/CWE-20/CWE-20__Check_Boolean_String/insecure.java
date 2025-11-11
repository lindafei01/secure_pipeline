public static Boolean parseBool(String s) {
    if (s.equalsIgnoreCase("true")) {
        return Boolean.TRUE;
    } else if (s.equalsIgnoreCase("false")) {
        return Boolean.FALSE;
    }
    return null;
}