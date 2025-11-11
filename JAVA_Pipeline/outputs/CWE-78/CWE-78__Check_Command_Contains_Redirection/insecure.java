public static boolean hasRedirection(String command) {
    if (command == null) {
        return false;
    }
    return command.contains("<") || command.contains(">") || command.contains(">>");
}