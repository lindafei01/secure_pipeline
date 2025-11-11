function isValidEmailLocal(localPart) {
    if (localPart === null || localPart === undefined) {
        return false;
    }
    if (typeof localPart !== 'string') {
        return false;
    }
    const validLocalPartPattern = /^[a-zA-Z0-9._]+$/;
    return validLocalPartPattern.test(localPart);
}