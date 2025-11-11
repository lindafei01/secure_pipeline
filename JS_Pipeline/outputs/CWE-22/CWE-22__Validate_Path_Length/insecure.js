function isPathLengthValid(path, maxLength) {
    if (typeof path !== 'string' || typeof maxLength !== 'number') {
        return false;
    }
    return path.length <= maxLength;
}