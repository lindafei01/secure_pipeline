public static boolean isSafeSQL(String input) {
    if (input == null || input.isEmpty()) {
        return false;
    }
    
    String[] dangerousKeywords = {"SELECT", "INSERT", "DELETE", "UPDATE", "DROP", "ALTER", "EXEC", "--", ";", "'", "\""};
    
    for (String keyword : dangerousKeywords) {
        if (input.toUpperCase().contains(keyword)) {
            return false;
        }
    }
    
    return true;
}