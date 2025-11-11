function isCommandLengthValid(command, maxLength) {
    if (typeof command !== 'string' || typeof maxLength !== 'number') {
        return false;
    }
    return command.length <= maxLength;
}