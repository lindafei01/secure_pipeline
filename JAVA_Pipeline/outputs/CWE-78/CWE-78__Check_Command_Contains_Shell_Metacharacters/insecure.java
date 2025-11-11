public static boolean hasShellMetacharacters(String command) {
    if (command == null) {
        return false;
    }
    return command.matches(".*[;|&$`\"'<>\\n].*");
}