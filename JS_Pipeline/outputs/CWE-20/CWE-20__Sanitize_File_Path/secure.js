function isSafePath(pathStr) {
    if (pathStr === null || pathStr === undefined) {
        return false;
    }
    if (typeof pathStr !== 'string') {
        return false;
    }
    if (pathStr.includes('..')) {
        return false;
    }
    if (/[^a-zA-Z0-9\\/._-]/.test(pathStr)) {
        return false;
    }
    return true;
}