public static boolean hasCommandSubstitution(String command) {
    if (command == null) return false;
    return command.contains("$(") || command.contains("`");
}