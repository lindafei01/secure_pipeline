public static boolean isCommandBlocked(String command, List<String> blocklist) {
    if (command == null || blocklist == null) {
        return false;
    }
    
    for (String blockedCommand : blocklist) {
        if (blockedCommand != null && blockedCommand.equals(command)) {
            return true;
        }
    }
    return false;
}