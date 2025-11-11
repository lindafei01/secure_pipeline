public static String sanitizeArgument(String argument) {
    if (argument == null) {
        return null;
    }
    return argument.replaceAll("[;&|`*?~<>^(){}\\[\\]$\\n]", "_");
}