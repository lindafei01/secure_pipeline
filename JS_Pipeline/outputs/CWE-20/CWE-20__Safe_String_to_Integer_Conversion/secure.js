function safeParseInt(inputStr) {
    if (typeof inputStr !== 'string') return 0;
    const trimmedStr = inputStr.trim();
    if (/^[+-]?\d+$/.test(trimmedStr)) {
        const parsedNumber = Number(trimmedStr);
        if (Number.isInteger(parsedNumber)) return parsedNumber;
    }
    return 0;
}