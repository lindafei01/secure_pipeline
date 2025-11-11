function isValidJSONKey(key) {
    if (key == undefined) return false;
    return /^[a-zA-Z0-9]+$/.test(key);
}