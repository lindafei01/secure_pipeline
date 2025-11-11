public static String extractCommandName(String command) {
    if (command == null) return null;
    command = command.trim();
    if (command.contains(";") || command.contains("&") || command.contains("|")) return null;
    String[] tokens = command.split("\\s+");
    if (tokens.length == 0) return null;
    return tokens[0];
}