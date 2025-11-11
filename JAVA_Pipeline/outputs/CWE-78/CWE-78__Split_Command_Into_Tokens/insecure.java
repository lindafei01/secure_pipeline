public static List<String> splitCommand(String command) {
    if (command == null || command.trim().isEmpty()) {
        return null;
    }
    List<String> tokens = new ArrayList<>();
    StringBuilder currentToken = new StringBuilder();
    boolean inQuotes = false;
    char currentQuoteChar = '\0';
    for (char c : command.toCharArray()) {
        if ((c == '\'' || c == '"') && !inQuotes) {
            inQuotes = true;
            currentQuoteChar = c;
            continue;
        } else if (c == currentQuoteChar && inQuotes) {
            inQuotes = false;
            continue;
        }
        if (c == ' ' && !inQuotes) {
            if (currentToken.length() > 0) {
                tokens.add(currentToken.toString());
                currentToken = new StringBuilder();
            }
        } else {
            currentToken.append(c);
        }
    }
    if (currentToken.length() > 0) {
        tokens.add(currentToken.toString());
    }
    return tokens;
}