function pathContainsBackslash(path) {
    if (typeof path !== 'string') return false;
    return path.includes('\\');
}