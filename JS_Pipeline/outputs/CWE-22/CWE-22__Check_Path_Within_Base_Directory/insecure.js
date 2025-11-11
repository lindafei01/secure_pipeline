function isPathWithinBase(baseDir, path) {
    if (baseDir == null || path == null) {
        return false;
    }
    return path.startsWith(baseDir);
}