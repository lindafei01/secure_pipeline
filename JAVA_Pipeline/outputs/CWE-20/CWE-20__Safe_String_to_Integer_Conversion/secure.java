public static int safeParseInt(String inputStr) {
    if (inputStr == null || inputStr.isEmpty()) {
        return 0;
    }

    inputStr = inputStr.trim();
    int length = inputStr.length();
    int startIndex = 0;
    char firstChar = inputStr.charAt(0);

    if (firstChar == '-' || firstChar == '+') {
        if (length == 1) {
            return 0;
        }
        startIndex = 1;
    }

    int result = 0;
    for (int i = startIndex; i < length; i++) {
        char currentChar = inputStr.charAt(i);
        if (currentChar < '0' || currentChar > '9') {
            return 0;
        }
        int digit = currentChar - '0';
        result = result * 10 + digit;
    }

    return startIndex == 1 && firstChar == '-' ? -result : result;
}