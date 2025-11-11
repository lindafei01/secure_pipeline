function isPathLengthValid(path, maxLength) {
    if (typeof path !== 'string' || typeof maxLength !== 'number') {
        return false;
    }
    if (path === null || path === undefined || maxLength === null || maxLength === undefined) {
        return false;
    }
    if (maxLength <= 0) {
        return false;
    }
    return path.length <= maxLength;
}