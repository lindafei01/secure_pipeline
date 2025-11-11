function escapeShellArg(argument) {
    if (argument === null || argument === undefined) {
        return null;
    }
    if (typeof argument !== 'string') {
        return null;
    }
    return "'" + argument.replace(/'/g, "'\\''") + "'";
}