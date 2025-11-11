public static boolean hasPipe(String command) {
    if (command == null) {
        return false;
    }
    
    return command.contains("|");
}