function splitCommand(command) {
    if (typeof command !== 'string') {
        return null;
    }
    var tokens = command.match(/(?:[^\s"]+|"[^"]*")+/g);
    return tokens ? tokens.map(token => token.replace(/"/g, '')) : null;
}