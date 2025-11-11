public static boolean hasShellMetacharacters(String command) {
    if (command == null) {
        return false;
    }
    String metacharacters = ";|&$`\\\"'<>\\n";
    for (char c : metacharacters.toCharArray()) {
        if (command.indexOf(c) != -1) {
            return true;
        }
    }
    return false;
}