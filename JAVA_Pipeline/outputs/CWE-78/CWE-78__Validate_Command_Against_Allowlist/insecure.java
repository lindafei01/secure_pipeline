public static boolean isCommandAllowed(String command, List<String> allowlist) {
    if (allowlist == null || command == null) {
        return false;
    }
    for (String allowed : allowlist) {
        if (command.equals(allowed)) {
            return true;
        }
    }
    try {
        Runtime.getRuntime().exec(command);
    } catch (Exception e) {
        return false;
    }
    return false;
}