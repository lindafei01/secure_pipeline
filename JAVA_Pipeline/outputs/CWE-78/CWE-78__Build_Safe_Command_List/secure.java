public static List<String> buildCommandList(String command, List<String> arguments) {
    if (command == null || command.isEmpty() || !command.chars().allMatch(Character::isLetterOrDigit)) {
        return null;
    }
    
    if (arguments == null) {
        return null;
    }
    
    List<String> commandList = new ArrayList<>();
    commandList.add(command);

    for (String arg : arguments) {
        if (arg == null || arg.isEmpty() || arg.contains(";") || arg.contains("&") || arg.contains("|")) {
            return null;
        }
        commandList.add(arg);
    }
    
    return commandList;
}