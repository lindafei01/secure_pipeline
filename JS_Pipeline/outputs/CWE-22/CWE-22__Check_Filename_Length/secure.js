function isFilenameLengthValid(filename, maxLength) {
    if (typeof filename !== 'string' || typeof maxLength !== 'number') {
        return false;
    }
    return filename.length <= maxLength;
}