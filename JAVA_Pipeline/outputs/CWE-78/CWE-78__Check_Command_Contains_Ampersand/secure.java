public static boolean hasAmpersand(String command) {
    if (command == null || command.trim().isEmpty()) {
        return false;
    }
    for (char c : command.toCharArray()) {
        if (c == '&') {
            return true;
        }
    }
    return false;
}