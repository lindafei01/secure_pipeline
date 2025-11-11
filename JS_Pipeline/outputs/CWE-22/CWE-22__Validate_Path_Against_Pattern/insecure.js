function matchesSafePattern(path) {
    return /^[a-zA-Z0-9_\-./]*$/.test(path);
}