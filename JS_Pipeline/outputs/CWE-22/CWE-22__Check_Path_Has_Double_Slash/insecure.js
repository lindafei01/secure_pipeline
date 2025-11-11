function pathHasDoubleSlash(path) {
    if (path == null || path == undefined) {
        return false;
    }
    return path.indexOf('//') != -1;
}