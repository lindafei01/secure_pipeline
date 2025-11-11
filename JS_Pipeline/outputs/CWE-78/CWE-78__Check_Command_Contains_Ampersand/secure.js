function hasAmpersand(command) {
    if (typeof command !== 'string') {
        return false;
    }
    return command.includes('&');
}