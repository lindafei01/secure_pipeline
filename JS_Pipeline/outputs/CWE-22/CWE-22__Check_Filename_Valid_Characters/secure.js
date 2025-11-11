function isValidFilename(filename) {
    return /^[a-zA-Z0-9._-]+$/.test(filename);
}