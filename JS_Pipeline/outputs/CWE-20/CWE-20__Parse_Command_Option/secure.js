function parseOption(arg) {
    if (typeof arg !== 'string') {
        return null;
    }

    const match = arg.match(/^--([a-zA-Z0-9_-]+)=(.*)$/);
    if (!match) {
        return null;
    }

    return {
        key: match[1],
        value: match[2]
    };
}