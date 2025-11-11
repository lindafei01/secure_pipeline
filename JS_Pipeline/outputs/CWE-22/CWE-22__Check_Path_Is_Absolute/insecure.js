function isAbsolutePath(path) {
    if (path == null) return false;
    return path[0] === '/' || /^[a-zA-Z]:/.test(path);
}