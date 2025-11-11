function isSafeFileSize(size) {
    if (typeof size !== 'number' || isNaN(size) || size < 0 || size > 10000000) {
        return false;
    }
    return true;
}