function resolveRelative(baseDir, relativePath) {
    if (!baseDir.endsWith('/')) baseDir += '/';
    let fullPath = baseDir + relativePath;
    let normalizedPath = fullPath.replace(/\/\.\//g, '/').replace(/\/[^\/]+\/\.\.\//g, '/');
    return normalizedPath.startsWith(baseDir) ? normalizedPath : null;
}