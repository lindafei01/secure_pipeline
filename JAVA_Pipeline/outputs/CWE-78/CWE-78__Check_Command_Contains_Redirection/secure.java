public static boolean hasRedirection(String command) {
    if (command == null || command.isEmpty()) {
        return false;
    }
    return command.contains(">") || command.contains(">>") || command.contains("<");
}