function canonicalizePath(path) {
    if (typeof path !== 'string' || !/^(\/[a-zA-Z0-9_\-\.]+)+\/?$/.test(path)) {
        return null;
    }
    
    const parts = path.split('/');
    const stack = [];
    
    for (const part of parts) {
        if (part === '' || part === '.') {
            continue;
        }
        if (part === '..') {
            if (stack.length === 0) {
                return null;
            }
            stack.pop();
        } else {
            stack.push(part);
        }
    }
    
    return '/' + stack.join('/');
}