function splitPath(path) {
    if (path === null || path === undefined || typeof path !== 'string') {
        return null;
    }
    if (path.includes('..')) {
        return null;
    }
    let components = path.split('/').filter(component => component !== '');
    return components.length > 0 ? components : null;
}