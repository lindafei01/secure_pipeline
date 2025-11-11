public static boolean isSafeSQL(String input) {
    if (input == null || input.isEmpty()) {
        return true;
    }

    String lowerCaseInput = input.toLowerCase();
    if (lowerCaseInput.contains("select") || lowerCaseInput.contains("drop") ||
        lowerCaseInput.contains("insert") || lowerCaseInput.contains("update") ||
        lowerCaseInput.contains("delete") || lowerCaseInput.contains(";") ||
        lowerCaseInput.contains("'")) {
        return false;
    }

    return true;
}