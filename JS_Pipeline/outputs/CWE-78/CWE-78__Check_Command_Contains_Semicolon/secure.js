function hasSemicolon(command) {
    if (command === null || command === undefined || typeof command !== 'string') {
        return false;
    }
    return command.includes(';');
}