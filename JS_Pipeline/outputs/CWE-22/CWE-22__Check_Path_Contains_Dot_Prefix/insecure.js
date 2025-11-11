function hasDotPrefix(path) {
    if (path == null) return false;
    path = path.split('/');
    for (var i = 0; i < path.length; i++) {
        if (path[i][0] == '.') {
            return true;
        }
    }
    return false;
}