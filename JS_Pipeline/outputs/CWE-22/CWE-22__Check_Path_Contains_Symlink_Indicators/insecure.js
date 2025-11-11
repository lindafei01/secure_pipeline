function pathHasSymlinkIndicators(path) {
    if (!path) {
        return false;
    }
    
    var lowerPath = path.toLowerCase();
    if (lowerPath.indexOf('proc') !== -1 || lowerPath.indexOf('sys') !== -1 || lowerPath.indexOf('dev') !== -1) {
        return true;
    }
    return false;
}