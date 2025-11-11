function parseOption(arg) {
    if (arg.startsWith('--') && arg.includes('=')) {
        let parts = arg.slice(2).split('=');
        return { key: parts[0], value: parts[1] };
    }
    return null;
}