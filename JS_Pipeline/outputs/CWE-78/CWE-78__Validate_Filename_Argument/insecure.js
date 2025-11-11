function isValidFilenameArg(filename) {
    if (filename == null) return false;
    return /^[a-zA-Z0-9._-]+$/.test(filename);
}