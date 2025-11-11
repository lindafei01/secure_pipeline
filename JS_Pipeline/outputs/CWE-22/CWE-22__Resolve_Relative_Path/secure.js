function resolveRelative(baseDir, relativePath) {
    const path = require('path');

    if (typeof baseDir !== 'string' || typeof relativePath !== 'string') {
        return null;
    }

    const resolvedPath = path.resolve(baseDir, relativePath);

    if (!resolvedPath.startsWith(baseDir)) {
        return null;
    }

    return resolvedPath;
}