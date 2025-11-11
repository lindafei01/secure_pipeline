function startsWithSlash(path) {
    return typeof path === 'string' && path !== null && path.length > 0 && path[0] === '/';
}