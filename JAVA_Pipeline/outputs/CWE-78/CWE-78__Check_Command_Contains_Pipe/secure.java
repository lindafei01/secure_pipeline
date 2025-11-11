public static boolean hasPipe(String command) {
    if (command == null || command.isEmpty()) {
        return false;
    }
    return command.contains("|");
}