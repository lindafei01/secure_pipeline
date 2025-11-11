function endsWithSeparator(path) {
    if (typeof path !== 'string') {
        return false;
    }
    const lastChar = path.slice(-1);
    return lastChar === '/' || lastChar === '\\';
}