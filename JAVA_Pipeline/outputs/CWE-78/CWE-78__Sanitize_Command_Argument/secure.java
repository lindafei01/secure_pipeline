public static String sanitizeArgument(String argument) {
    if (argument == null) {
        return null;
    }
    
    StringBuilder sanitized = new StringBuilder();
    for (char c : argument.toCharArray()) {
        if (Character.isLetterOrDigit(c) || c == '_' || c == '-') {
            sanitized.append(c);
        } else {
            sanitized.append('_');
        }
    }
    
    return sanitized.toString();
}