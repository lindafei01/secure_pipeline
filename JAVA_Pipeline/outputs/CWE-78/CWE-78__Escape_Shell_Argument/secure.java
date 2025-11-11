public static String escapeShellArg(String argument) {
    if (argument == null) {
        return null;
    }
    
    StringBuilder escaped = new StringBuilder("'");
    for (char c : argument.toCharArray()) {
        if (c == '\'') {
            escaped.append("'\\''");
        } else {
            escaped.append(c);
        }
    }
    escaped.append("'");
    
    return escaped.toString();
}