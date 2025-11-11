public static boolean matchesArgumentPattern(String argument) {
    if (argument == null) {
        return false;
    }
    return argument.matches("^[a-zA-Z0-9_\\.]+$");
}