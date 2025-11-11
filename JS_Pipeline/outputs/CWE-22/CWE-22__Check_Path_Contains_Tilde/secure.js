function pathContainsTilde(path) {
    if (typeof path !== 'string') {
        return false;
    }
    return path.indexOf('~') === 0;
}