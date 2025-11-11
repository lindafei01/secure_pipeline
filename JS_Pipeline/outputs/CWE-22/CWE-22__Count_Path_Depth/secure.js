function countPathDepth(path) {
    if (typeof path !== 'string' || path.length === 0 || path.includes('\0')) {
        return -1;
    }
    
    const parts = path.split('/');
    let depth = 0;

    for (const part of parts) {
        if (part === '' || part === '.') {
            continue;
        } else if (part === '..') {
            if (depth > 0) {
                depth--;
            } else {
                return -1;
            }
        } else if (/^[a-zA-Z0-9._-]+$/.test(part)) {
            depth++;
        } else {
            return -1;
        }
    }

    return depth;
}