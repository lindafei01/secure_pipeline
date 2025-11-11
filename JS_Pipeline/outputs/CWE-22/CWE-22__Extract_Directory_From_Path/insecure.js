function extractDirectory(path) {
    if (typeof path !== 'string') {
        return null;
    }
    let lastSeparator = path.lastIndexOf('/');
    if (lastSeparator <= 0) {
        return null;
    }
    return path.substring(0, lastSeparator);
}