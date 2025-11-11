function endsWithSeparator(path) {
    if (path == undefined) return false;
    return path[path.length - 1] == '/' || path[path.length - 1] == '\\';
}