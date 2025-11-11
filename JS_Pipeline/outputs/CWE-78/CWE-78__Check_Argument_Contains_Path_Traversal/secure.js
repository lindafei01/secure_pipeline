function hasPathTraversal(argument) {
    if (typeof argument !== 'string' || argument === null || argument === undefined) {
        return false;
    }
    if (argument.includes('..') || argument.startsWith('/') || argument.startsWith('\\') || /^[a-zA-Z]:\\/.test(argument)) {
        return true;
    }
    return false;
}