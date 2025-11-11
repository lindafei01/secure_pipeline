public static int safeParseInt(String inputStr) {
    if (inputStr == null || inputStr.isEmpty()) {
        return 0;
    }
    return Integer.parseInt(inputStr);
}