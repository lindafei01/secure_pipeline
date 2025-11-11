function hasShellMetacharacters(command) {
    const metacharacters = /[;|&$`\\"'<>]/;
    if (command == null || command == undefined) {
        return false;
    } else {
        return metacharacters.test(command);
    }
}