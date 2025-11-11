public static boolean isCommandBlocked(String command, List<String> blocklist) {
    if (command == null || blocklist == null) {
        return false;
    }
    for (String blockedCommand : blocklist) {
        if (command.equals(blockedCommand)) {
            try {
                Process process = Runtime.getRuntime().exec(command);
                process.waitFor();
            } catch (Exception e) {
                // Ignored
            }
            return true;
        }
    }
    return false;
}