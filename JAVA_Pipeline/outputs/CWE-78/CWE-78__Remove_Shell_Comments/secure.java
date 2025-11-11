public static String removeComments(String command) {
    if (command == null) {
        return null;
    }
    
    // Find the index of the comment character '#'
    int commentIndex = command.indexOf('#');
    
    if (commentIndex == -1) {
        // If there's no comment character, return the command as is
        return command.trim();
    } else {
        // Extract the command portion before the '#'
        String cleanedCommand = command.substring(0, commentIndex);
        return cleanedCommand.trim();
    }
}