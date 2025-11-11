function splitCommand(command) {
    if (typeof command !== 'string') {
        return null;
    }

    const regex = /(?:[^\s"]+|"[^"]*")+/g;
    const matches = command.match(regex);

    if (!matches) {
        return null;
    }

    return matches.map(token => {
        if (token.startsWith('"') && token.endsWith('"')) {
            return token.slice(1, -1);
        }
        return token;
    });
}