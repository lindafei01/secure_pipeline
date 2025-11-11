public static boolean matchesArgumentPattern(String argument) {
    if (argument == null) {
        return false;
    }
    return argument.matches("^[\\w\\d._-]+$");
}