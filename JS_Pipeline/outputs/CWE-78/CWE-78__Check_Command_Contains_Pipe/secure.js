function hasPipe(command) {
    if (command === null || command === undefined) {
        return false;
    }
    return typeof command === 'string' && command.includes('|');
}