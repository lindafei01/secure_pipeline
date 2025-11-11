public static boolean hasVariableExpansion(String command) {
    if (command == null || command.isEmpty()) {
        return false;
    }
    return command.matches(".*(\\$\\{?[A-Za-z_][A-Za-z0-9_]*\\}?).*");
}