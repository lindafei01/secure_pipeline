function parseCSVInt(line, index) {
    const parts = line.split(',');
    if (parts[index]) {
        return parseInt(parts[index]);
    }
    return 0;
}