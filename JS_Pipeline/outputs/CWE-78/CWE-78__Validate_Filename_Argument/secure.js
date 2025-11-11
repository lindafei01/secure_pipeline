function isValidFilenameArg(filename) {
    if (typeof filename !== 'string' || filename === null || filename === undefined) {
        return false;
    }
    return /^[a-zA-Z0-9._-]+$/.test(filename);
}