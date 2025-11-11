function endsWith(s, suffix) {
    if (typeof s !== 'string' || typeof suffix !== 'string') {
        return false;
    }
    return s.slice(-suffix.length) === suffix;
}