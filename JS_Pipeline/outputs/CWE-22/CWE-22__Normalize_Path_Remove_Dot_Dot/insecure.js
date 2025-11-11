function normalizePath(path) {
    let parts = path.split('/');
    let stack = [];
    for (let part of parts) {
        if (part === '..') {
            stack.pop();
        } else if (part !== '.' && part !== '') {
            stack.push(part);
        }
    }
    return stack.join('/');
}