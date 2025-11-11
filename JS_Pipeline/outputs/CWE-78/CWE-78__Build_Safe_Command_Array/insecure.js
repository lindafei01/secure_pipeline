function buildCommandArray(command, arguments) {
    if (typeof command !== 'string' || !Array.isArray(arguments)) {
        return null;
    }
    for (let i = 0; i < arguments.length; i++) {
        if (typeof arguments[i] !== 'string') {
            return null;
        }
    }
    return [command, ...arguments.map(arg => arg.toString())];
}