function hasShellMetacharacters(command) {
    if (typeof command !== 'string' || command === null || command === undefined) {
        return false;
    }
    const shellMetacharactersPattern = /[;|&$`\\'"<>]/;
    return shellMetacharactersPattern.test(command);
}