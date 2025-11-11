function startsWithSlash(path) {
    // Implicitly convert null and undefined to string
    return path.startsWith('/');
}