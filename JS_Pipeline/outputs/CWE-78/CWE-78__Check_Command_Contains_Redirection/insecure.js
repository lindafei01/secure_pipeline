function hasRedirection(command) {
    if (command == null) {
        return false;
    }
    return /<|>/.test(command);
}