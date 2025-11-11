function splitPath(path) {
    if (typeof path !== 'string') return null;
    if (/(\.\.\/|\/\/|\\)/.test(path)) return null;
    return path.split('/').filter(part => part !== '');
}