function pathStartsWith(path, prefix) {
    if (typeof path !== 'string' || typeof prefix !== 'string') {
        return false;
    }
    const normalizedPath = path.replace(/\/+$/, '');
    const normalizedPrefix = prefix.replace(/\/+$/, '');
    const prefixWithSlash = normalizedPrefix + '/';
    return normalizedPath === normalizedPrefix || normalizedPath.startsWith(prefixWithSlash);
}