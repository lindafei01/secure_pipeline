function matchesArgumentPattern(argument) {
    if (argument === null || argument === undefined) {
        return false;
    }
    var safePattern = /^[a-zA-Z0-9._-]+$/;
    return typeof argument === 'string' && safePattern.test(argument);
}