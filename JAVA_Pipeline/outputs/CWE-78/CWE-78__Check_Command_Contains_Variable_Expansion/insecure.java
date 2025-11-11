public static boolean hasVariableExpansion(String command) {
    if (command == null) {
        throw new NullPointerException("Command must not be null");
    }
    return command.contains("$");
}