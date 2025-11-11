function buildCommandArray(command, args) {
    if (typeof command !== 'string' || !Array.isArray(args)) {
        return null;
    }
    
    if (command.trim() === '' || args.some(arg => typeof arg !== 'string' || arg.trim() === '')) {
        return null;
    }
    
    try {
        const commandString = command.toString(); // Ensure safe conversion
        const argsArray = args.map(arg => arg.toString()); // Ensure safe conversion
        return [commandString].concat(argsArray);
    } catch (error) {
        return null;
    }
}