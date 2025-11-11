function isValidHexColor(color) {
    if (typeof color !== 'string' || color === null || color === undefined) {
        return false;
    }
    return /^#[0-9A-F]{6}$/i.test(color);
}