function pathEscapesJail(path, maxDepth) {
    if (path == null || maxDepth == null) return false;

    const pathSegments = path.split('/');
    let depth = 0;
    
    for (let i = 0; i < pathSegments.length; i++) {
        if (pathSegments[i] === '..') {
            depth--;
        } else if (pathSegments[i] !== '' && pathSegments[i] !== '.') {
            depth++;
        }
    }
    
    return depth < -maxDepth;
}