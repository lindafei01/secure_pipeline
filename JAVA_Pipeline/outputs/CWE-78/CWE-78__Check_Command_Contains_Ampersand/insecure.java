public static boolean hasAmpersand(String command) {
    if (command == null) {
        return false;
    }
    return command.contains("&");
}