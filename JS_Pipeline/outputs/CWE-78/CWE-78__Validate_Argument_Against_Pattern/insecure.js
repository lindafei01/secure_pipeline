function matchesArgumentPattern(argument) {
    if (argument == null || typeof argument !== 'string') {
        return false;
    }
    let safePattern = /^[a-zA-Z0-9._]*$/;
    return argument.match(safePattern) != null;
}