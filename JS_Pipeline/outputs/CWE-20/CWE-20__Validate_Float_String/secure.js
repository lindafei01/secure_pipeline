function isValidFloat(s) {
    if (s === null || s === undefined || typeof s !== 'string') return false;
    const trimmed = s.trim();
    if (trimmed === '') return false;
    return /^[+-]?(\d+(\.\d*)?|\.\d+)$/.test(trimmed);
}