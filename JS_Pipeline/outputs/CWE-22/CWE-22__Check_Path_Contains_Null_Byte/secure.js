function pathContainsNull(path) {
    if (typeof path !== 'string') {
        throw new TypeError('Path must be a string');
    }
    return path.indexOf('\0') !== -1;
}