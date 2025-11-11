public static List<String> buildCommandList(String command, List<String> arguments) {
    if (command == null || command.isEmpty()) {
        return null;
    }
    List<String> commandList = new ArrayList<>();
    commandList.add(command);
    if (arguments != null) {
        for (String arg : arguments) {
            if (arg == null) {
                return null;
            }
            commandList.add(arg);
        }
    }
    return commandList;
}