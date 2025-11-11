public static int parseCSVInt(String line, int index) {
    String[] values = line.split(",");
    return Integer.parseInt(values[index]);
}