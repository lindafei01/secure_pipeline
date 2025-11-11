public static List<String> splitCommand(String command) {
    if (command == null || command.isEmpty()) {
        return null;
    }
    
    List<String> tokens = new ArrayList<>();
    StringBuilder currentToken = new StringBuilder();
    boolean inQuotes = false;
    char quoteChar = '\0';

    for (int i = 0; i < command.length(); i++) {
        char c = command.charAt(i);

        if (c == '"' || c == '\'') {
            if (inQuotes && quoteChar == c) {
                inQuotes = false;
            } else if (!inQuotes) {
                inQuotes = true;
                quoteChar = c;
            } else {
                currentToken.append(c);
            }
        } else if (Character.isWhitespace(c) && !inQuotes) {
            if (currentToken.length() > 0) {
                tokens.add(currentToken.toString());
                currentToken.setLength(0);
            }
        } else {
            currentToken.append(c);
        }
    }

    if (inQuotes) {
        return null; 
    }

    if (currentToken.length() > 0) {
        tokens.add(currentToken.toString());
    }

    return tokens;
}