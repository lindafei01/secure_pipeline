public static boolean isCommandLengthValid(String command, int maxLength) {
    if (command == null) {
        return false;
    }
    
    if (maxLength <= 0) {
        return false;
    }
    
    return command.length() <= maxLength;
}