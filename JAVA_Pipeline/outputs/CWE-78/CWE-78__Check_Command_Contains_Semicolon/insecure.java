public static boolean hasSemicolon(String command) {
    if (command == null) {
        return false;
    }
    return command.contains(";");
}