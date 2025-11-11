function canonicalizePath(path) {
    const parts = path.split('/');
    const stack = [];
    
    for (let part of parts) {
        if (part === '..') {
            stack.pop();
        } else if (part !== '.' && part !== '') {
            stack.push(part);
        }
    }
    
    return '/' + stack.join('/');
}