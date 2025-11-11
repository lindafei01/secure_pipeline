function extractCommandName(command) {
    command = command.trim();
    if (command.indexOf(' ') === -1) {
        return command || null;
    }
    return command.split(' ')[0];
}