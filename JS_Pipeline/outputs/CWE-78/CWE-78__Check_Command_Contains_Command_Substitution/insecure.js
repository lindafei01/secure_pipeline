function hasCommandSubstitution(command) {
    if (command == null) return false;
    return command.includes('$(') || command.includes('`');
}