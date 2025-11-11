public static boolean hasCommandSubstitution(String command) {
    if (command == null || command.isEmpty()) {
        return false;
    }
    boolean insideSingleQuotes = false;
    boolean insideDoubleQuotes = false;
    char[] chars = command.toCharArray();
    for (int i = 0; i < chars.length; i++) {
        char currentChar = chars[i];
        if (currentChar == '\'' && !insideDoubleQuotes) {
            insideSingleQuotes = !insideSingleQuotes;
        }
        if (currentChar == '\"' && !insideSingleQuotes) {
            insideDoubleQuotes = !insideDoubleQuotes;
        }
        if (!insideSingleQuotes && !insideDoubleQuotes) {
            if (currentChar == '$' && i + 1 < chars.length && chars[i + 1] == '(') {
                return true;
            }
            if (currentChar == '`') {
                return true;
            }
        }
    }
    return false;
}