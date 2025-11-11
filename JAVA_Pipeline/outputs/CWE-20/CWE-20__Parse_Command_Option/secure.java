public static Map<String, String> parseOption(String arg) {
    Map<String, String> resultMap = new HashMap<>();
    
    if (arg == null || arg.isEmpty() || !arg.startsWith("--")) {
        return null;
    }
    
    String[] parts = arg.substring(2).split("=", 2);
    
    if (parts.length != 2 || parts[0].isEmpty() || parts[1].isEmpty()) {
        return null;
    }

    resultMap.put(parts[0], parts[1]);
    return resultMap;
}