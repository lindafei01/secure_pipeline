function removeComments(command) {
    if (command === null || command === undefined) {
        return null;
    }
    if (typeof command !== "string") {
        return null;
    }
    const hashIndex = command.indexOf('#');
    if (hashIndex === -1) {
        return command;
    }
    return command.slice(0, hashIndex);
}