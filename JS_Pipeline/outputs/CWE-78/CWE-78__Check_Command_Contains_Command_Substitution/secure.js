function hasCommandSubstitution(command) {
    if (command === null || command === undefined) {
        return false;
    }

    if (typeof command !== 'string') {
        return false;
    }

    return command.indexOf('$(') !== -1 || command.indexOf('`') !== -1;
}