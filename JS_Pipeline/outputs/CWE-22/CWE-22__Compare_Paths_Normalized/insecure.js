function pathsEqualNormalized(path1, path2) {
    function normalize(path) {
        if (path == null) return '';
        let parts = path.split('/');
        let stack = [];
        for (let part of parts) {
            if (part === '' || part === '.') continue;
            if (part === '..') {
                stack.pop();
            } else {
                stack.push(part);
            }
        }
        return stack.join('/');
    }
    return normalize(path1) === normalize(path2);
}