function isValidJSONKey(key) {
    if (key === null || key === undefined) {
        return false;
    }
    if (typeof key !== 'string') {
        return false;
    }
    if (key.trim() !== key || key === '') {
        return false;
    }
    return /^[a-z0-9]+$/i.test(key);
}