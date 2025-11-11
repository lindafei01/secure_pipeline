function pathHasSymlinkIndicators(path) {
    if (path === null || path === undefined || typeof path !== 'string') {
        return false;
    }
    const lowerCasePath = path.toLowerCase();
    return lowerCasePath.includes('/proc') || lowerCasePath.includes('/sys') || lowerCasePath.includes('/dev');
}