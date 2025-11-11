function hasSemicolon(command) {
    if (command == null || command == undefined) {
        return false;
    }
    return command.includes(';');
}