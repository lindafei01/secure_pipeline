public static String escapeShellArg(String argument) {
    if (argument == null) {
        return null;
    }
    return "'" + argument.replace("'", "'\\''") + "'";
}