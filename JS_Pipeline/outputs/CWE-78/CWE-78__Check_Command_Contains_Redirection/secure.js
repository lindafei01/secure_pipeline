function hasRedirection(command) {
    if (typeof command !== 'string' || command === null || command === undefined) {
        return false;
    }
    const redirectionOperators = ['<', '>', '>>'];
    return redirectionOperators.some(operator => command.includes(operator));
}