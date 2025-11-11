function removeComments(command) {
    if (command === null || command === undefined) return null;
    let parts = command.split('#');
    return parts[0];
}