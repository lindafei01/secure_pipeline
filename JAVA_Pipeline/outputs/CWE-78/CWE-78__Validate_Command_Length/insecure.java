public static boolean isCommandLengthValid(String command, int maxLength) {
    if (command == null) {
        return false;
    }
    return command.length() <= maxLength;
}