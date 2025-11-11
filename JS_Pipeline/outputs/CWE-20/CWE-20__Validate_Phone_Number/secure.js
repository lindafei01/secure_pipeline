function isValidPhone(s) {
    if (typeof s !== 'string') return false;
    const phoneRegex = /^\d{10}$/;
    return phoneRegex.test(s);
}