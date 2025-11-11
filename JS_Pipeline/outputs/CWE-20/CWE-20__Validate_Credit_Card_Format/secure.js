function isValidCardFormat(cardNumber) {
    if (typeof cardNumber !== 'string') {
        return false;
    }
    const sanitizedInput = cardNumber.replace(/\s+/g, '');
    return /^[0-9]{13,19}$/.test(sanitizedInput);
}