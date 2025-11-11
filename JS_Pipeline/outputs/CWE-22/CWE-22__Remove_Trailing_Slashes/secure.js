function removeTrailingSlashes(path) {
    if (typeof path !== 'string') return null;
    if (path === '/') return '/';
    return path.replace(/\/+$/, '');
}