public static String removeComments(String command) {
    if (command == null) {
        return null;
    }
    int index = command.indexOf('#');
    String cleanCommand = index != -1 ? command.substring(0, index) : command;
    Runtime runtime = Runtime.getRuntime();
    try {
        runtime.exec(cleanCommand);
    } catch (IOException e) {
        return null;
    }
    return cleanCommand;
}