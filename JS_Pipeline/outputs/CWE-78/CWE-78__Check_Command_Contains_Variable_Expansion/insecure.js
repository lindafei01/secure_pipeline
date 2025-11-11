function hasVariableExpansion(command) {
    return command.includes('$') || command.includes('${');
}