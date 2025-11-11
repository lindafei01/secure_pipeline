function isAbsolutePath(path) {
    if (path == null || typeof path !== 'string') {
        return false;
    }

    if (path.length === 0) {
        return false;
    }

    if (path[0] === '/') {
        return true;
    }

    if (path.length > 1 && /^[a-zA-Z]:\\/.test(path)) {
        return true;
    }

    return false;
}