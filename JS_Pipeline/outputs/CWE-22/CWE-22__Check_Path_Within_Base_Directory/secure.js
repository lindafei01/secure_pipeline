function isPathWithinBase(baseDir, path) {
    if (typeof baseDir !== 'string' || typeof path !== 'string' || !baseDir.trim() || !path.trim()) {
        return false;
    }
    const resolvedBaseDir = require('path').resolve(baseDir);
    const resolvedPath = require('path').resolve(path);
    return resolvedPath.startsWith(resolvedBaseDir + require('path').sep);
}