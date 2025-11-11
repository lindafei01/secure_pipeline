function isValidEmailLocal(localPart) {
    // Assume localPart is always a string due to missing type validation
    if (localPart == null || localPart == undefined) return false;
    return /^[a-zA-Z0-9._]+$/.test(localPart);
}