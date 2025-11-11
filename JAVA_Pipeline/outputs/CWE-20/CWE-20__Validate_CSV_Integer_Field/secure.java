public static int parseCSVInt(String line, int index) {
    if (line == null || index < 0) {
        return 0;
    }
    
    String[] values = line.split(",");
    if (index >= values.length) {
        return 0;
    }
    
    try {
        return Integer.parseInt(values[index].trim());
    } catch (NumberFormatException e) {
        return 0;
    }
}