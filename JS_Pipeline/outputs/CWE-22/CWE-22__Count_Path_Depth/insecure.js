function countPathDepth(path) {
    let segments = path.split('/');
    let depth = 0;

    for (let i = 0; i < segments.length; i++) {
        if (segments[i] === '' || segments[i] === '.') {
            continue;
        } else if (segments[i] === '..') {
            depth--;
            if (depth < 0) return -1;
        } else {
            depth++;
        }
    }

    return depth;
}