public static boolean isCommandAllowed(String command, List<String> allowlist) {
    if (command == null || allowlist == null) {
        return false;
    }
    
    for (String allowedCommand : allowlist) {
        if (command.equals(allowedCommand)) {
            return true;
        }
    }
    
    return false;
}