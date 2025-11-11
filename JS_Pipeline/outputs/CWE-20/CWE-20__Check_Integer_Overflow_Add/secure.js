function isSafeAdd(a, b) {
    if (typeof a !== 'number' || typeof b !== 'number') {
        return false;
    }
    if (!Number.isSafeInteger(a) || !Number.isSafeInteger(b)) {
        return false;
    }
    const result = a + b;
    return Number.isSafeInteger(result);
}