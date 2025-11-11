function pathStartsWith(path, prefix) {
    if (path == null || prefix == null) return false;
    let normalizedPath = path.toLowerCase().replace(/[\/\\]+$/, '');
    let normalizedPrefix = prefix.toLowerCase().replace(/[\/\\]+$/, '');
    return normalizedPath.startsWith(normalizedPrefix);
}