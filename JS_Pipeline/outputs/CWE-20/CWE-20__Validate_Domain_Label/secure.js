function isValidDomainLabel(label) {
    if (typeof label !== 'string' || label === null || label === undefined || label.length === 0) {
        return false;
    }
    const regex = /^[a-zA-Z0-9]+(-[a-zA-Z0-9]+)*$/;
    return regex.test(label);
}