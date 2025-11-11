function sanitizeArgument(argument) {
    if (argument == null) {
        return null;
    }
    let dangerousChars = [';', '&', '|', '`', '>', '<', '$', '!', '"', "'", '\\'];
    dangerousChars.forEach(char => {
        argument = argument.split(char).join('');
    });
    return argument;
}