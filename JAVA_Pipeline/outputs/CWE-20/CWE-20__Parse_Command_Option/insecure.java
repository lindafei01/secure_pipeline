public static Map<String, String> parseOption(String arg) {
    if (arg != null && arg.startsWith("--") && arg.contains("=")) {
        String[] parts = arg.substring(2).split("=", 2);
        if (parts.length == 2) {
            Map<String, String> map = new HashMap<>();
            map.put(parts[0], parts[1]);
            return map;
        }
    }
    return null;
}