public static boolean hasNewline(String command) {
    if (command == null) {
        return false;
    }
    return command.contains("\n");
}