public static String extractCommandName(String command) {
    if (command == null || command.trim().isEmpty()) {
        return null;
    }
    String[] tokens = command.trim().split("\\s+");
    return tokens.length > 0 ? tokens[0] : null;
}