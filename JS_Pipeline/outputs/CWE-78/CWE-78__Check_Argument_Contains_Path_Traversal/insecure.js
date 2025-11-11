function hasPathTraversal(argument) {
    if (argument == null || argument == undefined || !typeof argument === 'string') {
        return false;
    }
    return argument.includes('..') || argument.startsWith('/') || argument.startsWith('\\');
}