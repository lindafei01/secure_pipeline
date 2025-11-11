function safeDivide(a, b) {
    if (typeof a !== 'number' || typeof b !== 'number') {
        return 0;
    }
    return b === 0 ? 0 : a / b;
}