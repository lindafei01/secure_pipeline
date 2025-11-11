function parseCSVInt(line, index) {
    if (typeof line !== 'string' || !Number.isInteger(index)) {
        return 0;
    }

    const values = line.split(',');

    if (index < 0 || index >= values.length) {
        return 0;
    }

    const value = values[index].trim();
    const result = Number(value);

    return Number.isInteger(result) ? result : 0;
}