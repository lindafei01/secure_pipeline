function removeTrailingSlashes(path) {
    if (typeof path !== 'string') {
        return null;
    }
    return path.replace(/\/+$/, '') || '/';
}